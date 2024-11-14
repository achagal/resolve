import React from 'react';

function DownloadButton() {
    const handleDownload = () => {
        // Logic to display files from GitHub and download selected files
        console.log("Download button clicked");
    };

    return (
        <button onClick={handleDownload}>Download</button>
    );
}

export default DownloadButton;
