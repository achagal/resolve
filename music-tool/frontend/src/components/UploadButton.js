import React from 'react';

function UploadButton() {
    const handleUpload = () => {
        // Logic to open file selector and upload files
        console.log("Upload button clicked");
    };

    return (
        <button onClick={handleUpload}>Upload</button>
    );
}

export default UploadButton;
