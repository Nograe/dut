function select_answer(answer){
    document.getElementById("answer1").style.backgroundColor = "grey";
    document.getElementById("answer2").style.backgroundColor = "grey";
    document.getElementById("answer3").style.backgroundColor = "grey";
    document.getElementById("answer4").style.backgroundColor = "grey";
    document.getElementById("player").style.margin = "";

    document.getElementById("disp_answer").innerHTML = "Vous avez choisi la réponse " + answer;

    select = 0;
    
    if(answer == 1){
	document.getElementById("answer1").style.backgroundColor = "blue";
	document.getElementById("player").style.left = "15%";
	document.getElementById("player").style.top = "15%";
	document.getElementById("player").style.bottom = "auto";
	document.getElementById("player").style.right = "auto";
	select = 1;
    }
    if(answer == 2){
	document.getElementById("answer2").style.backgroundColor = "blue";
	document.getElementById("player").style.right = "15%";
	document.getElementById("player").style.top = "15%";
	document.getElementById("player").style.bottom = "auto";
	document.getElementById("player").style.left = "auto";
	select = 2;
    }
    if(answer == 3){
	document.getElementById("answer3").style.backgroundColor = "blue";
	document.getElementById("player").style.left= "15%";
	document.getElementById("player").style.bottom = "15%";
	document.getElementById("player").style.top = "auto";
	document.getElementById("player").style.right = "auto";
	select = 3;
    }
    if(answer == 4){
	document.getElementById("answer4").style.backgroundColor = "blue";
	document.getElementById("player").style.top = "auto";
	document.getElementById("player").style.left = "auto";
	document.getElementById("player").style.right = "15%";
	document.getElementById("player").style.bottom = "15%";
	select = 4;
    }

}

function timer(second){
   
    document.getElementById("player").style.left = "0";
    document.getElementById("player").style.right = "0";
    document.getElementById("player").style.top = "48%";    

    document.getElementById("answer1").style.backgroundColor = "";
    document.getElementById("answer2").style.backgroundColor = "";
    document.getElementById("answer3").style.backgroundColor = "";
    document.getElementById("answer4").style.backgroundColor = "";

    var current = 0;
    var progress = 80;
    document.getElementById("start").style.visibility = "hidden";
    //document.getElementById("disp_answer").style.visibility = "visible";

    document.getElementById("panswer1").style.visibility = "visible";
    document.getElementById("panswer1").style.visibility = "visible";
    document.getElementById("panswer1").style.visibility = "visible";
    document.getElementById("panswer1").style.visibility = "visible";

    var good = randomquestion();
    
    var timerp = setInterval( function() {

	document.getElementById("timer").innerHTML = second - (current++);
   document.getElementById("progressbar").style.width = progress + "%";
   progress -= 8;
	if(second - current < 3)
	    document.getElementById("timer").style.color = "red";
	if(second - current < -1){
            //alert("Le temps est écoulé!");
            clearInterval(timerp);
	    if(good == select)
		goodanswer();
	    else
		badanswer();
            return reset();
	}
    }, 1000);
}

function reset() {
 
    
    document.getElementById("timer").style.color = "white";
    document.getElementById("timer").innerHTML = "";

    //document.getElementById("disp_answer").innerHTML = "";

    document.getElementById("start").style.visibility = "visible";
    //document.getElementById("disp_answer").style.visibility = "hidden";

    document.getElementById("quest").style.visibility = "hidden";
    document.getElementById("panswer1").style.visibility = "hidden";
    document.getElementById("panswer2").style.visibility = "hidden";
    document.getElementById("panswer3").style.visibility = "hidden";
    document.getElementById("panswer4").style.visibility = "hidden";
}

function randomquestion() {

    var num = Math.floor((Math.random() * 5) + 1);
    var ans1 = 0; var ans2 = 0; var ans3 = 0; var ans4 = 0; var quest = 0;
    var good = 0;
    document.getElementById("quest").style.visibility = "visible";
    document.getElementById("panswer1").style.visibility = "visible";
    document.getElementById("panswer2").style.visibility = "visible";
    document.getElementById("panswer3").style.visibility = "visible";
    document.getElementById("panswer4").style.visibility = "visible";

    if(num == 1){
	quest = "Quel fruit entre dans la composition de la compote de pomme ?";
	ans1 = "Ananas";
	ans2 = "Pomme";
	ans3 = "Banane";
	ans4 = "Poire";
	good = 2;
    }
    if(num == 2){
	quest = "Pour faire avancer un vélo, on appuie sur ...";
	ans1 = "Les roues";
	ans2 = "Les freins";
	ans3 = "Les pédales";
	ans4 = "Les poignées";
	good = 3;
    }
    if(num == 3){
	quest = "Dans quel océan se situe l'archipel d'Hawaï ?";
	ans1 = "Océan Atlantique";
	ans2 = "Océan Arctique";
	ans3 = "Océan Indien";
	ans4 = "Océan Pacifique";
	good = 4;
    }
    if(num == 4){
	quest = "Lequel de ces éléments ne peut être 'moutarde' ?";
	ans1 = "Gaz";
	ans2 = "Sel";
	ans3 = "Colonel";
	ans4 = "Condiment";
	good = 2;
    }
    if(num == 5){
	quest = "Qui a découvert l'Amérique en 1492 ?";
	ans1 = "Marco Polo";
	ans2 = "Jacques Cartier";
	ans3 = "Christophe Colomb";
	ans4 = "Magellan";
	good = 3;
    }

    document.getElementById("quest").innerHTML = quest;
    document.getElementById("panswer1").innerHTML = ans1;
    document.getElementById("panswer2").innerHTML = ans2;
    document.getElementById("panswer3").innerHTML = ans3;
    document.getElementById("panswer4").innerHTML = ans4;

    return good;
}

function goodanswer() {
    document.getElementById("answer"+select).style.backgroundColor = "green";
    document.getElementById("score").innerHTML = "Score: "+(++score);
}

function badanswer() {
   if(select == 0)
      return reset();

   document.getElementById("answer"+select).style.backgroundColor = "red";
}

score = 0;