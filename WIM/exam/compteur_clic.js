function changeDigit (id) {
	var img = document.getElementById(id);
	if(img.id == "0") {
		img.id = "1";
		img.src = "digits/1.jpg";
		return;
	}
	if(img.id == "1") {
		img.id = "2";
		img.src = "digits/2.jpg";
		return;
	}
	if(img.id == "2") {
		img.id = "3";
		img.src = "digits/3.jpg";
		return;
	}
	if(img.id == "3") {
		img.id = "4";
		img.src = "digits/4.jpg";
		return;
	}
	if(img.id == "4") {
		img.id = "5";
		img.src = "digits/5.jpg";
		return;
	}
	if(img.id == "5") {
		img.id = "6";
		img.src = "digits/6.jpg";
		return;
	}
	if(img.id == "6") {
		img.id = "7";
		img.src = "digits/7.jpg";
		return;
	}
	if(img.id == "7") {
		img.id = "8";
		img.src = "digits/8.jpg";
		return;
	}
	if(img.id == "8") {
		img.id = "9";
		img.src = "digits/9.jpg";
		return;
	}
	if(img.id == "9") {
		img.id = "0";
		img.src = "digits/0.jpg";
		return;
	}
}
