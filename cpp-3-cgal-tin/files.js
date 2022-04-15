export class Files {
    static loadText(textfile) {
        return new Promise((resolve, reject) => {
            let reader = new FileReader();
            reader.readAsText(textfile);
            reader.onload = () => {
                // console.log(reader.result);
                resolve(reader.result);
            };
            reader.onerror = (error) => reject(error);
        });
    }
    
    static loadJSON(JSONfile) {
        return new Promise((resolve, reject) => {
            let reader = new FileReader();
            reader.readAsText(JSONfile);
            reader.onload = () => {
                // console.log(reader.result);
                resolve(JSON.parse(reader.result));
            };
            reader.onerror = (error) => reject(error);
        });
    }
    
    /**
     * 
     * @param {File} binaryFile 
     * @returns 
     */
     static loadBlob(binaryFile) {
        return binaryFile.arrayBuffer();
    }
    
    /**
     * Write a string to a file, and download it to the user's download folder. 
     * @param {string} file 
     * @param {string} text 
     */
    static writeAndDownload(filename, text) {
        var element = document.createElement("a");
        element.setAttribute("href", "data:text/plain;charset=utf-8, " + encodeURIComponent(text));
        element.setAttribute("download", filename);
        document.body.appendChild(element);
        element.click();
        document.body.removeChild(element);
        element.remove();
    }
    
}

