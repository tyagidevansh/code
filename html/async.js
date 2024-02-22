const posts = [
    {title : 'Post One', body : 'This is post one'},
    {title : 'Post Two', body : 'This is post two'}
];

function getPosts() {
    setTimeout(() => {
        output = '';
        posts.forEach((post, index) => {
            output += `<li>${post.title}</l1>`
        });
        document.body.innerHTML = output;
    }, 1000);
}

function createPosts(post) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            posts.push(post);

            const error = false;

            if (!error) {
                resolve();
            } else {
                reject("Error: Something went wrong");
            }
        }, 2000);
    });
}

// async function fetchUsers() {
//     const res = await fetch();
//     const data = await res.json();
//     console.log(data);
// }

// fetchUsers();

// async function init() {
//     await createPosts({title : 'Post Three', body : 'This is post three'});
//     getPosts();
// }

// init();

//getPosts();
// createPosts({title : 'Post Three', body : 'This is post three'})
//     .then(getPosts)
//     .catch(err => console.log(err));

// const promise1 = Promise.resolve("Hello World");
// const promise2 = 10;
// const promise3 = new Promise((resolve, reject) => setTimeout(resolve, 2000, 'Goodbye'));

// Promise.all([promise1, promise2, promise3]).then(values => console.log(values));