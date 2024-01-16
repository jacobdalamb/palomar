$(() => {
	$("#mysubmit").click(() => {
		$(".error").text("");

		const selectedYear = $("#years").val();
		const firstName = $("#first_name").val();
		const lastName = $("#last_name").val();
		const selectedGender = $('input[name="gender"]:checked').val();

		if (firstName === "") {
			$("#first_error").text("Must enter first name");
			$("#first_name").focus();
		} else if (lastName === "") {
			$("#last_error").text("Must enter last name");
			$("#last_name").focus();
		} else if (!selectedGender) {
			$("#gender_error").text("Must choose a Gender");
		} else if (selectedYear === "-") {
			$("#years_error").text("Must choose a Year");
		} else {
			const name = `${firstName} ${lastName}`;
			const genderText = selectedGender === "M" ? "Male" : "Female";

			$("#message").css("background-color", "yellow");
			$("#message").css("padding-left", "3rem");
			$("#message").css("padding-bottom", "5rem");
			$("#message").css("display", "grid");
			$("#message").html(
				`<h1>Employment Stats for ${name}</h1>
   <br>
   <span>You are a: ${genderText}</span>
   <span>You have: ${selectedYear} years of experience</span>`,
			);
		}
	});
});
