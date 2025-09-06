function greet(name) {
    const hour = new Date().getHours();
    let timeGreeting = "Hello";

    if (hour < 12) {
        timeGreeting = "Good morning";
    } else if (hour < 18) {
        timeGreeting = "Good afternoon";
    } else {
        timeGreeting = "Good evening";
    }

    const message = `${timeGreeting}, ${name}!`;
    console.log(message);
    return message;
}

function farewell(name) {
    return `Goodbye, ${name}!`;
}
