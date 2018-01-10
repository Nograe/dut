document.addEventListener("contextmenu", function(e) {
    e.preventDefault();
}, false);
document.getElementsByTagName("html")[0].setAttribute("onmousedown", "myFunction(event);");

function myFunction(e) {
    var verif = 1;
    if (e.button == 0) {
        console.log("Bouton gauche pressé!");
        var para = document.createElement("p");
        var node = document.createTextNode("DESTROY THE WEB.");
        para.appendChild(node);
        e.target.appendChild(para);
    }
    if (e.button == 1) {
        console.log("Bouton du milieu pressé!");
        if (e.target.childNodes[0] == Node.TEXT_NODE) {
            console.log("Le premier Node de cet élémént est un élément texte!");
            e.target.replaceChild(e.target.ChildNodes[0], document.createTextNode("DESTROY THE WEB."));
        }
        if (e.target.childElementCount == 0) {
            console.log("Cet élément ne contient pas de ChildNodes!");
            e.target.replaceChild(e.target, document.createTextNode("DESTROY THE WEB."));
        }
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
