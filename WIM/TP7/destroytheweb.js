document.getElementsByTagName("html")[0].setAttribute("onmousedown", "myFunction(event);");
function myFunction (e) {
    var verif = 1;
    if(e.button == 0) {
	console.log("Bouton gauche pressé!");
    }
    if(e.button == 1) {
	console.log("Bouton du milieu pressé!");
    }
    if(e.button == 2) {
	console.log("Bouton droit pressé!");
	console.log("Cet élément contient:"+e.target.childElementCount+" éléments");
	var echild = e.target.childNodes;
	for(var i = 0; i < e.target.childElementCount; i++) {
	    if(echild[i].nodeType != Node.TEXT_NODE) {
		console.log("Cet élément n'est pas de type texte: "+echild[i]);
		verif = 0;
	    }
	}
	if(verif)
	    e.target.remove();
    }
}
