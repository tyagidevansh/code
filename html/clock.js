function updateClock(){
    const now = new Date();
    const hour = now.getHours() % 12;
    const minutes = now.getMinutes();
    const seconds = now.getSeconds();

    const hourHand = document.querySelector('.hour-hand');
    const minuteHand = document.querySelector('.minute-hand');
    const secondHand = document.querySelector('.second-hand');

    const hourDegrees = (hour * 30) + (minutes * 0.5); // 30 degrees per hour, 0.5 degrees per minute
    const minuteDegrees = (minutes * 6) + (seconds * 0.1); // 6 degrees per minute, 0.1 degrees per second
    const secondDegrees = seconds * 6; // 6 degrees per second

    hourHand.style.transform = `rotate(${hourDegrees}deg)`;
    minuteHand.style.transform = `rotate(${minuteDegrees}deg)`;
    secondHand.style.transform = `rotate(${secondDegrees}deg)`;
}
setInterval(updateClock, 1000);