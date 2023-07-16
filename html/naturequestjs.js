// Sample event data
let events = [
    {
      title: "Hiking Adventure",
      date: "June 15, 2023",
      location: "National Park",
      description: "Join us for an exciting hiking adventure through scenic trails.",
    },
    {
      title: "Nature Photography Workshop",
      date: "June 20, 2023",
      location: "Botanical Garden",
      description: "Learn the art of nature photography from experts in this workshop.",
    },
  ];
  
  // Function to generate event listings
  function generateEventListings() {
    const eventListDiv = document.getElementById("event-list");
    
    events.forEach(event => {
      const eventDiv = document.createElement("div");
      eventDiv.classList.add("event");
      
      const title = document.createElement("h3");
      title.textContent = event.title;
      
      const date = document.createElement("p");
      date.textContent = "Date: " + event.date;
      
      const location = document.createElement("p");
      location.textContent = "Location: " + event.location;
      
      const description = document.createElement("p");
      description.textContent = event.description;
      
      eventDiv.appendChild(title);
      eventDiv.appendChild(date);
      eventDiv.appendChild(location);
      eventDiv.appendChild(description);
      
      eventListDiv.appendChild(eventDiv);
    });
  }
  
  // Function to add a new event
  function addEvent() {
    const titleInput = document.getElementById("title-input");
    const dateInput = document.getElementById("date-input");
    const locationInput = document.getElementById("location-input");
    const descriptionInput = document.getElementById("description-input");
    
    // Create a new event object
    const newEvent = {
      title: titleInput.value,
      date: dateInput.value,
      location: locationInput.value,
      description: descriptionInput.value,
    };
    
    // Add the new event to the events array
    events.push(newEvent);
    
    // Clear the input fields
    titleInput.value = "";
    dateInput.value = "";
    locationInput.value = "";
    descriptionInput.value = "";
    
    // Call the function to regenerate event listings
    generateEventListings();
  }
  
  // Call the function to generate initial event listings
  generateEventListings();
  