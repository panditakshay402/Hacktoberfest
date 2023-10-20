fetch('https://api.example.com/data')
  .then(response => {
    if (!response.ok) {
      throw new Error('Network response was not ok');
    }
    return response.json(); // Assuming the response is in JSON format
  })
  .then(data => {
    // Handle the data
    console.log(data);
  })
  .catch(error => {
    // Handle errors
    console.error('Error:', error);
  });
