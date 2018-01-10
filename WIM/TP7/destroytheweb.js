document.addEventListener("contextmenu", function(e) {
    e.preventDefault();
}, false); // On désactive l'action du clic droit (ouverture de fenêtre)
document.getElementsByTagName("html")[0].setAttribute("onmousedown", "myFunction(event);"); // On ajoute à la page une fonction qui réagit au clic

function myFunction(e) {
    var verif = 1;
    if (e.button == 0) {
        console.log("Bouton gauche pressé!");
        // On ajoute un Child de type texte à l'élément
        var node = document.createTextNode("DESTROY THE WEB.");
        e.target.appendChild(node);
    }
    if (e.button == 1) {
        console.log("Bouton du milieu pressé!");
        // Si l'élément ne contient pas de Child, on quitte
        if(e.target.childNodes.length == 0) {
           console.log("Cet élémént ne contient pas de Child!");
           return;
        }
        // Si le premier Child est de type texte, on lui ajoute un titre h3 qui lui-même contient le premier Child
        if (e.target.childNodes[0].nodeType == Node.TEXT_NODE) {
            console.log("Le premier Node de cet élémént est un élément texte!");
            var newel = document.createElement("h3");
            newel.appendChild(e.target.childNodes[0]);
            e.target.insertBefore(newel, e.target.childNodes[0]);
        }
        // Si le premier Child n'est pas de type texte, on quitte
        else if (e.target.childNodes[0] != Node.TEXT_NODE)
            console.log("Le premier Node de cet élémént n'est pas un élément texte!");
    }
    if (e.button == 2) {
        console.log("Bouton droit pressé!");
        // On vérifie que chaque Child de l'élément est de type texte, puis on supprime l'élément
        if(e.target.childNodes.length == 0) { {
            verif = 1;
        }
        var echild = e.target.childNodes;
        for (var i = 0; i < e.target.childElementCount; i++) {
            if (echild[i].nodeType != Node.TEXT_NODE) {
                console.log("Cet élément n'est pas de type texte: " + echild[i]);
                verif = 0;
            }
        }
        if (verif)
            e.target.remove();
    }
}
