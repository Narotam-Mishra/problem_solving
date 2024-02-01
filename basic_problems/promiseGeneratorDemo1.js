
// promise with generator function example - 1

function downloader(url) {
    return new Promise((res, rej) => {
        console.log("Started downloading from", url);
        setTimeout(() => {
            console.log("Download completed");
            let downloadedData = "Dummy content";
            res(downloadedData); 
        }, 4000);
    })
}

function writeFile(data) {
    return new Promise((res, rej) => {
        console.log("Started writing data", data);
        setTimeout(() => {
            console.log("Writing completed");
            // with the written content, whatever you want to do you can do
            let fileName = "Dummy.txt";
            res(fileName); // cb -> any callback
        }, 2000);
    })
    
}

function uploadFile(fileName, newUrl) {

    return new Promise((res, rej) => {
        console.log("Started uploading file", fileName, "on the url", newUrl);
        setTimeout(() => {
            console.log("Upload completed");
            // with the uploaded content, whatever you want to do you can do
            let uploadResponse = "SUCESSS";
            res(uploadResponse); // cb -> any callback
        }, 3000);
    });
   
}

function doAfterReceiving(value){
    const f = iterator.next(value);
    if(f.done === true) return;
    f.value.then(doAfterReceiving);
}

function* steps(){
    const downloadedData = yield downloader("https://www.google.com");
    console.log('Downloaded data is:', downloadedData) ;
    const fileName = yield writeFile(downloadedData);
    console.log('File written:', fileName);
    const upload = yield uploadFile(fileName, "https://drive.google.com");
    console.log("Upload Response:",upload);
}

const iterator = steps(); // this will not start the function execution
// iterator is a global object
const future = iterator.next(); // future -> {value: Promise, done: false}

future.value.then(doAfterReceiving);