export async function loadText(textfile) {
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

export async function loadJSON(JSONfile) {
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
export function loadBlob(binaryFile) {
    return binaryFile.arrayBuffer();
}