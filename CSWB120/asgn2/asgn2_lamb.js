const $ = (id) => document.getElementById(id);

const displayMessage = () => {
	const myFirstName = $("firstname").value;
	const myLastName = $("lastname").value;
	const numPets = $("numpets").value;
	const numPetsInt = parseInt(numPets);
	const today = new Date();
	const todaymm = today.getMonth() + 1;
	const todaydd = today.getDate();
	const todayyyy = today.getFullYear();
	const todayformatted = `${todaymm}-${todaydd}-${todayyyy}`;
	let numOfErrors = 0;
	let petNames = "";

	if (myFirstName === "") {
		$("firstname_error").innerHTML = "Please enter your first name";
		numOfErrors++;
	}
	if (myLastName === "") {
		$("lastname_error").innerHTML = "Please enter your last name";
		numOfErrors++;
	}

	if (numPets === "") {
		$("numpets_error").innerHTML = "Please enter the number of pets you have";
		numOfErrors++;
	} else if (Number.isNaN(numPetsInt)) {
		$("numpets_error").innerHTML = "Please enter a number";
		numOfErrors++;
	}

	if (numPets > 3 || numPets < 0) {
		$("numpets_error").innerHTML = "Please enter a number between 0 and 3";
		numOfErrors++;
	}

	for (cntr = 1; cntr <= numPetsInt; cntr++) {
		const petId = `pet${cntr}`;
		const petName = $(petId).value;

		petNames += `Your Pet #${cntr} is named ${petName}. `;
	}

	let myText = "";

	if (numOfErrors === 0) {
		myText = `Your name is listed as ${myLastName}, ${myFirstName} and today's date is ${todayformatted}. ${petNames}`;
	}
	$("message").innerHTML = myText;
};

window.onload = () => {
	$("mybutton").onclick = displayMessage;
};
