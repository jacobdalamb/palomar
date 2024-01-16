const $ = (id) => document.getElementById(id);

const displayName = () => {
	const myFirstName = $("firstname").value;
	const myAge = $("age").value;
	const myHoursSlept = $("hours-slept").value;
	const yearsSlept = Math.round(myAge * (myHoursSlept / 24));
	const myText = `Hi ${myFirstName}. You have slept ${yearsSlept} ${
		yearsSlept === 1 ? "year" : "years"
	} of your life away.`;
	$("mymsg").innerHTML = myText;
};

window.onload = () => {
	$("mybutton").onclick = displayName;
};
