var liste = document.querySelectorAll("ul");

function addPoint(liste) {
	if(liste.length <= 0)
		return;
	for(var i = 0; i < liste.length; i++) {
        	var node = document.createElement("li");
		node.innerHTML = "Exam WIM";
        	liste[i].appendChild(node);
	}
}

addPoint(liste);
