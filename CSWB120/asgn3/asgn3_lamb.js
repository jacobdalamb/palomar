const $ = (id) => document.getElementById(id);

function validateItems() {
	$("firstnameerror").innerHTML = "";
	$("lastnameerror").innerHTML = "";
	$("emailerror").innerHTML = "";
	$("cityerror").innerHTML = "";
	$("donationerror").innerHTML = "";
	const myFirstName = $("firstname").value;
	const myLastName = $("lastname").value;
	const myEmail = $("email").value;
	const citySelect = $("city").value;
	const donation = $("donation").value;
	const numDonationInt = parseInt(donation);
	let numOfErrors = 0;

	if (myFirstName === "") {
		$("firstnameerror").innerHTML = "Enter First Name";
		numOfErrors++;
	}

	if (myLastName === "") {
		$("lastnameerror").innerHTML = "Enter Last Name";
		numOfErrors++;
	}

	if (myEmail === "") {
		$("emailerror").innerHTML = "Enter Email";
		numOfErrors++;
	}

	if (citySelect === "-") {
		$("cityerror").innerHTML = "Select a City from the list";
		numOfErrors++;
	}

	if (donation === "") {
		$("donationerror").innerHTML = "Enter Donation Amount";
		numOfErrors++;
	} else if (Number.isNaN(numDonationInt)) {
		$("donationerror").innerHTML = "Amount must be numeric";
		numOfErrors++;
	}

	return numOfErrors === 0;
}

function clearFields() {
	$("firstname").value = "";
	$("lastname").value = "";
	$("email").value = "";
	$("donation").value = "";
	$("city").value = "-";
	$("firstnameerror").innerHTML = "";
	$("lastnameerror").innerHTML = "";
	$("emailerror").innerHTML = "";
	$("cityerror").innerHTML = "";
	$("donationerror").innerHTML = "";
	$("endmessage").innerHTML = "";
}

function addPatron() {
	const isValid = validateItems();
	const donation = $("donation").value;
	const myText = "Patron Not Added!";

	if (isValid) {
		const form = $("patronform");
		form.submit();
	} else {
		$("endmessage").innerHTML = "Patron Not Added!";
	}
}

window.onload = () => {
	$("addpatron").onclick = addPatron;
	$("clearfields").onclick = clearFields;
};
