const inputBox = document.getElementById("input-box");
const listContainer = document.querySelector(".list-container");
const AddBtn = document.querySelector(".addbtn");
// console.log(inputBox);
// console.log(listContainer);

AddBtn.addEventListener("click", function () {
  if (inputBox.value === "") {
    alert("You need to write something!");
  } else {
    let li = document.createElement("li");
    li.innerHTML = inputBox.value;
    listContainer.appendChild(li);

    let span = document.createElement("span");
    span.innerHTML = "\u00d7";
    li.appendChild(span);
  }
  inputBox.value = "";
  storeData();
});

listContainer.addEventListener("click", function (e) {
  // console.log(e.target.tagName);
  if (e.target.tagName === "LI") {
    e.target.classList.toggle("checked");
    storeData();
  } else if (e.target.tagName === "SPAN") {
    e.target.parentElement.remove();
    storeData();
  }
});

function storeData() {
  localStorage.setItem("data", listContainer.innerHTML);
}

function showTask() {
  listContainer.innerHTML = localStorage.getItem("data");
}
showTask();
