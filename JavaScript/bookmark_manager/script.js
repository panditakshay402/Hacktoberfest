// Select elements
const bookmarkForm = document.getElementById('bookmarkForm');
const bookmarkUrl = document.getElementById('bookmarkUrl');
const bookmarkList = document.getElementById('bookmarkList');

// Retrieve bookmarks from localStorage
let bookmarks = JSON.parse(localStorage.getItem('bookmarks')) || [];

// Function to display bookmarks
function displayBookmarks() {
  bookmarkList.innerHTML = '';
  bookmarks.forEach((bookmark, index) => {
    bookmarkList.innerHTML += `
      <div class="flex justify-between items-center p-2 bg-gray-700 rounded">
        <a href="${bookmark}" target="_blank" class="text-blue-400 hover:underline">${bookmark}</a>
        <button onclick="deleteBookmark(${index})" class="text-red-500 hover:text-red-700">Delete</button>
      </div>
    `;
  });
}

// Function to add a new bookmark
bookmarkForm.addEventListener('submit', (e) => {
  e.preventDefault();
  const url = bookmarkUrl.value;

  // Add bookmark and save to localStorage
  bookmarks.push(url);
  localStorage.setItem('bookmarks', JSON.stringify(bookmarks));

  // Clear input and update the list
  bookmarkUrl.value = '';
  displayBookmarks();
});

// Function to delete a bookmark
function deleteBookmark(index) {
  bookmarks.splice(index, 1);
  localStorage.setItem('bookmarks', JSON.stringify(bookmarks));
  displayBookmarks();
}

// Display bookmarks on page load
displayBookmarks();
