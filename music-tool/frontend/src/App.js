import React from 'react';
import UploadButton from './components/UploadButton';
import DownloadButton from './components/DownloadButton';

function App() {
    return (
        <div>
            <h1>Music Tool</h1>
            <UploadButton />
            <DownloadButton />
        </div>
    );
}

export default App;
