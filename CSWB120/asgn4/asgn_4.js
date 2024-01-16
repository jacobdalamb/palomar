const $ = (id) => document.getElementById(id);

let BeatlesArray = [];

function resetBorders() {
	$("john").style.border = "0px";
	$("paul").style.border = "0px";
	$("george").style.border = "0px";
	$("ringo").style.border = "0px";
}

function addName(name) {
	BeatlesArray.push(name);
}

function processImages() {
	const johnImage = $("john");
	const paulImage = $("paul");
	const georgeImage = $("george");
	const ringoImage = $("ringo");

	resetBorders();

	if (johnImage) {
		johnImage.addEventListener("click", () => {
			resetBorders();
			johnImage.style.border = "4px solid yellow";
			addName("John");
		});
	}

	if (paulImage) {
		paulImage.addEventListener("click", () => {
			resetBorders();
			paulImage.style.border = "4px solid yellow";
			addName("Paul");
		});
	}

	if (georgeImage) {
		georgeImage.addEventListener("click", () => {
			resetBorders();
			georgeImage.style.border = "4px solid yellow";
			addName("George");
		});
	}

	if (ringoImage) {
		ringoImage.addEventListener("click", () => {
			resetBorders();
			ringoImage.style.border = "4px solid yellow";
			addName("Ringo");
		});
	}
}

function showList() {
	const list = $("list");
	let listString = "";
	for (let i = 0; i < BeatlesArray.length; i++) {
		listString += `${i + 1}. ${BeatlesArray[i]}`;
		if (i < BeatlesArray.length - 1) {
			listString += ", ";
		}
	}
	list.innerHTML = listString;
}

window.onload = () => {
	BeatlesArray = [];
	processImages();
	$("showlist").addEventListener("click", showList);
};
