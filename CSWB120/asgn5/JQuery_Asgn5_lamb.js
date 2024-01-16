let isImageClicked = false;

$(() => {
	$("img").hover(
		function () {
			$(this).css("border", "outset 10px");
		},
		function () {
			$(this).css("border", "none");
		},
	);

	$("#vacationimages p img").click(function () {
		isImageClicked = true;
		const copyPhotoSrc = $(this).attr("src");
		const copyPhotoAlt = $(this).attr("alt");
		$("#currentimage").attr("src", copyPhotoSrc);
		$("#currentimage").attr("alt", copyPhotoAlt);
		$("#imagedesc").text(copyPhotoAlt);
		$("#bigimage").css("display", "block");
	});

	$("#submitme").click(() => {
		if ($("#firstname").val() === "") {
			$("span").text("Must enter first name");
		} else if ($("#firstname").val() !== "" && isImageClicked) {
			const name = $("#firstname").val();
			const vacation = $("#imagedesc").text();
			$("#mymessage").text(`${name} you want a ${vacation}`);
		}
	});

	$("#showhidebutton").click(function () {
		if (isImageClicked) {
			$("#bigimage").css("display", "none");
			$(this).val("Show Image");
			isImageClicked = false;
		} else {
			$("#bigimage").css("display", "block");
			$(this).val("Hide Image");
			isImageClicked = true;
		}
	});
});
