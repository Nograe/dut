document.addEventListener("contextmenu", function(e) {
    e.preventDefault();
}, false);
document.getElementsByTagName("html")[0].setAttribute("onmousedown", "myFunction(event);");

function myFunction(e) {
    var verif = 1;
    if (e.button == 0) {
        console.log("Bouton gauche pressé!");
        var node = document.createTextNode("DESTROY THE WEB.");
        e.target.appendChild(node);
    }
    if (e.button == 1) {
        console.log("Bouton du milieu pressé!");
        if(e.target.childNodes.length == 0)
           return;
        if (e.target.childNodes[0].nodeType == Node.TEXT_NODE) {
            console.log("Le premier Node de cet élémént est un élément texte!");
            var newel = document.createElement("h3");
            newel.appendChild(e.target.childNodes[0]);
            e.target.insertBefore(newel, e.target.childNodes[0]);
        }
        else if (e.target.childNodes[0] != Node.TEXT_NODE)
            console.log("Le premier Node de cet élémént n'est pas un élément texte!");
    }
    if (e.button == 2) {
        console.log("Bouton droit pressé!");
        console.log("Cet élément contient:" + e.target.childElementCount + " éléments");
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
