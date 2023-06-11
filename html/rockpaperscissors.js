const computerChoiceDisplay = document.getElementById('computer-choice')
const userChoiceDisplay = document.getElementById('user-choice')
const resultDisplay = document.getElementById('result')
const possibleChoices = document.querySelectorAll('button')

let userChoice
let computerChoice
let result
possibleChoices.forEach(possibleChoice => possibleChoice.addEventListener('click', (e) => {
    userChoice = e.target.id
    userChoiceDisplay.innerHTML = userChoice
    generateComputerChoice()
    getResult()
}))

function generateComputerChoice(){
    const randomNumber = Math.floor(Math.random()*possibleChoices.length+1)
    
    if(randomNumber == 1){
        computerChoice = 'rock';
    }

    if(randomNumber == 2){
        computerChoice = 'scissors';
    }

    if(randomNumber == 3){
        computerChoice = 'paper';
    }
    computerChoiceDisplay.innerHTML = computerChoice;

}

function getResult(){
    if (computerChoice == userChoice){
        result = "Its a draw!"
    }
    else if (
        (userChoice === 'rock' && computerChoice === 'scissors') ||
        (userChoice === 'paper' && computerChoice === 'rock') ||
        (userChoice === 'scissors' && computerChoice === 'paper')
    ){ result = "You win!";}

    else {result = "Computer wins!";}
    resultDisplay.innerHTML = result;
}

//.html bit
<h2> Computer Choice: <span id="computer-choice"></span></h2>
<h2> Your choice: <span id="user-choice"></span></h2>
<h2> Result: <span id="result"></span></h2>

<button id="rock"> rock </button>
<button id = "paper"> paper</button>
<button id = "scissors"> scissors</button>
