$(document).ready(() => {
	$("#tabs").tabs();

	$("#datepicker").datepicker();

	let selectedPlan = null;

	$("#great-plan, #poor-plan").draggable({ cursor: "move" });

	$("#drop").droppable({
		drop: function (event, ui) {
			selectedPlan = ui.draggable.attr("id");
			if (selectedPlan === "great-plan") {
				$(this)
					.addClass("ui-state-highlight")
					.find("h4")
					.html("Great Plan Picked!");
			} else if (selectedPlan === "poor-plan") {
				$(this)
					.addClass("ui-state-highlight")
					.find("h4")
					.html("Poor Plan Picked!");
			}
		},
	});

	const callback = () => {
		setTimeout(() => {
			const currentColor = $("#feelings-message h3").css("color");
			$("#feelings-message h3").removeAttr("style").fadeIn();
			$("#feelings-message h3").css("color", currentColor);
		}, 1000);
	};

	$("#feelings").click(() => {
		const feelingsMessage = $("#feelings-message h3");
		if (!selectedPlan) {
			feelingsMessage.effect("bounce", { times: 3 }, 300).text("I don't know");
		} else if (selectedPlan === "poor-plan") {
			feelingsMessage
				.effect("shake", {}, 500, callback)
				.css("color", "red")
				.text("My Head Hurts!");
		} else if (selectedPlan === "great-plan") {
			feelingsMessage
				.effect("blind", {}, 500, callback)
				.css("color", "green")
				.text("Great!");
		}
	});
});

$(() => {
	$("#mysubmit").click(() => {
		$(".error").text("");

		const firstName = $("#first_name").val();
		const lastName = $("#last_name").val();
		const datePicker = $("#datepicker").val();

		const fields = [
			{
				value: firstName,
				errorId: "#first_error",
				message: "Must Enter First Name",
			},
			{
				value: lastName,
				errorId: "#last_error",
				message: "Must Enter Last Name",
			},
			{
				value: datePicker,
				errorId: "#date_error",
				message: "Please Enter the Start Date",
			},
		];

		let error = false;

		for (const field of fields) {
			if (field.value === "") {
				$(field.errorId).text(field.message);
				if (!error) {
					error = true;
				}
			}
		}

		const name = `${firstName} ${lastName}`;

		if (error) {
			$("#error-message").css("color", "red");
			$("#error-message").text("Please Correct Errors and Try Again");
		} else {
			$("#error-message").css("color", "green");
			$("#error-message").html(
				`<p>Success: ${name} <br/> Use the Start Date as your Password </p>`,
			);
		}
	});
});
