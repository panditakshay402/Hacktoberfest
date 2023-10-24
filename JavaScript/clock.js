// Get the clock element
var clockElement = document.getElementById("clock");

// Set the clock
function setClock() {
  // Get the current time
  var now = new Date();

  // Get the hours, minutes, and seconds
  var hours = now.getHours();
  var minutes = now.getMinutes();
  var seconds = now.getSeconds();

  // Format the time
  var time = `${hours}:${minutes}:${seconds}`;

  // Update the clock element
  clockElement.innerHTML = time;
}

// Set the clock every second
setInterval(setClock, 1000);
