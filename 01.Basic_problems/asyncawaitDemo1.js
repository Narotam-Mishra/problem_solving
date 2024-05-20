
// async await Demo example - 1

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

async function steps(){
    const downloadedData = await downloader("https://www.google.com");
    console.log('Downloaded data is:', downloadedData) ;
    const fileName = await writeFile(downloadedData);
    console.log('File written:', fileName);
    const upload = await uploadFile(fileName, "https://drive.google.com");
    console.log("Upload Response:",upload);
}

steps();