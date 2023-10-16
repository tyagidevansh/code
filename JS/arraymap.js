const persons = [
    {firstname : "Malcolm", lastname : "Reynolds"},
    {firstname : "Kaylee", lastname : "Frye"},
    {firstname : "Jayne", lastname : "Cobb"}
];

const fullName = persons.map(getFullName);

function getFullName(item) {
    return item.firstname + " " + item.lastname;
}

console.log("Full names: "x);
console.log(fullName.join(", "));