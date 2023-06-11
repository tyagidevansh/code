document.addEventListener('DOMContentLoaded',() => {

    const cardArray = [
        {
            name: 'fries', 
            img: 'images/fries.png'
        },
        {
            name: 'cheeseburger', 
            img: 'images/cheeseburger.png'
        },
        {
            name: 'ice-cream', 
            img: 'images/ice-cream.png'
        },
        {
            name:'hotdog',
            img: 'images/hotdog.png'
        },
        {
            name: 'milkshake', 
            img: 'images/milkshake.png'
        },
        {
            name: 'pizza', 
            img: 'images/pizza.png'
        },
        {
            name: 'fries', 
            img: 'images/fries.png'
        },
        {
            name: 'cheeseburger', 
            img: 'images/cheeseburger.png'
        },
        {
            name: 'ice-cream', 
            img: 'images/ice-cream.png'
        },
        {
            name:'hotdog',
            img: 'images/hotdog.png'
        },
        {
            name: 'milkshake', 
            img: 'images/milkshake.png'
        },
        {
            name: 'pizza', 
            img: 'images/pizza.png'
        }
    ]

    cardArray.sort(() => 0.5- Math.random());

    const gridDisplay = document.querySelector('#grid');
    const resultDisplay = document.querySelector('#result');
    let cardsChosen=[];
    let cardsChosenId= [];
    let cardsWon = [];

    console.log(gridDisplay);


    function createBoard(){
        for (let i = 0; i < 12; i++){
            const card = document.createElement('img');
            card.setAttribute('src', 'images/blank.png');
            card.setAttribute('data-id', i);
            gridDisplay.appendChild(card);
            card.addEventListener('click', flipCard);
        }
    }

    function checkwin(){
        const cards = document.querySelectorAll('img');
        const optionOneId = cardsChosenId[0];
        const optionTwoId = cardsChosenId[1];
        
        if (optionOneId == optionTwoId){
            cards[optionOneId].setAttribute('src', 'images/blank.png');
            cards[optionTwoId].setAttribute('src','images/blank.png');
        }

        if (cardsChosen[0]=== cardsChosen[1]){
            cards[optionOneId].setAttribute('src','images/white.png');
            cards[optionTwoId].setAttribute('src','images/white.png');
            cards[optionOneId].removeEventListener('click', flipCard);
            cards[optionTwoId].removeEventListener('click', flipCard);
            cardsWon.push(cardsChosen);
        }

        else{
            cards[optionOneId].setAttribute('src','images/blank.png');
            cards[optionTwoId].setAttribute('src','images/blank.png');   
        }

        cardsChosen=[];
        cardsChosenId=[];
        resultDisplay.textContent = cardsWon.length;
        if (cardsWon.length === cardArray.length/2){
            resultDisplay.textContent = 'Congratulations! You found them all!'
        }
    }

    function flipCard() {
        let cardId = this.getAttribute('data-id');
        cardsChosen.push(cardArray[cardId].name);
        cardsChosenId.push(cardId);
        this.setAttribute('src', cardArray[cardId].img);
        if (cardsChosen.length === 2){
            setTimeout(checkwin, 500);
        }
    
    }

    createBoard();
})
