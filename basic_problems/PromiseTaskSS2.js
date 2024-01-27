
/*

Write three dummy functions using promises, All three functions are dummy, you dont need actual implementation. These dummy functions are to just represent a delay.

Write a function to download data from a url
Write a function to save that downloaded data in a file and return the filename
Write a function to upload the file written in previous step to a newurl

function downloader(url, cb) {
    // write a dummy impl using setTimeout to show a delay 
}

function writeFile(data, cb) {
    // write a dummy impl using setTimeout to show a delay 
}

function uploadFile(fileName, newUrl, cb) {
     // write a dummy impl using setTimeout to show a delay 
}

The download should take say 4sec delay, filewrite should take 2sec delay, upload should take 3sec delay
Write the above callbacks and use them in a manner that first download happens then writefile happens and then upload happens

Link -  https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise/then#onfulfilled

*/

function downloader(url) {
    // anyone who wants to download something first then and execute something else can use this function
    new Promise((resolve, reject) => {
        console.log('Download started from given URL:', url);
        setTimeout(() => {
            console.log("Download completed");
            // with the downloaded content, whatever you want to do you can do
            let downloadData = "Download content";
            resolve(downloadData);
        },4000)
    })
}

function writeFile(data) {
    new Promise((resolve, reject) => {
        console.log('Started writing into file with given data:', data);
        setTimeout(() => {
            console.log("Writing completed");
            // with the written content, whatever you want to do you can do
            let fileName = "DummyFile1.txt";
            resolve(fileName);
        },2000)
    })
}


function uploadFile(fileName, newUrl) {
    new Promise((resolve, reject) => {
        console.log(`Started uploading file ${fileName} on ${newUrl}`);
        setTimeout(() => {
            console.log("File uploading completed");
            // with the written content, whatever you want to do you can do
            let uploadResponse = "Upload Successfull";
            resolve(uploadResponse);
        },3000) 
    })
}

downloader("https://jsonplaceholder.typicode.com/posts")
    .then((downloadData) => writeFile(downloadData))
    .then((fileName) => uploadFile(fileName))
    .then((uploadResponse) => {
        console.log("Status of file upload", uploadResponse);
    })
    .catch((error) => {
        console.log("Getting this error:", error);
    });




