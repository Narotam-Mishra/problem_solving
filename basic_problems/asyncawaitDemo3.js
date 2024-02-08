// async await Demo example - 3

function downloader(url) {
    return new Promise((res, rej) => {
        console.log("Started downloading from", url);
        console.log("Download completed");
        let downloadedData = "Dummy content";
        res(downloadedData); 
    })
}

function writeFile(data) {
    return new Promise((res, rej) => {
        console.log("Started writing data", data);
        console.log("Writing completed");
        // with the written content, whatever you want to do you can do
        let fileName = "Dummy.txt";
        res(fileName); // cb -> any callback
    })
    
}

function uploadFile(fileName, newUrl) {
    return new Promise((res, rej) => {
        console.log("Started uploading file", fileName, "on the url", newUrl);
        console.log("Upload completed");
        // with the uploaded content, whatever you want to do you can do
        let uploadResponse = "SUCESSS";
        res(uploadResponse); // cb -> any callback
    });
   
}

async function executor(){
    const downloadedData = await downloader("https://www.google.com");
    console.log('Downloaded data is:', downloadedData) ;
    const fileName = await writeFile(downloadedData);
    console.log('File written:', fileName);
    const upload = await uploadFile(fileName, "https://drive.google.com");
    console.log("Upload Response:",upload);
}

console.log("Start...");
executor();
console.log("End!!");