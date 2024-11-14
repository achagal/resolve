fn main() {
    tauri::Builder::default()
        .invoke_handler(tauri::generate_handler![upload_files, download_files])
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}

#[tauri::command]
fn upload_files() {
    // Logic to handle file upload to GitHub
    println!("Uploading files...");
}

#[tauri::command]
fn download_files() {
    // Logic to handle file download from GitHub
    println!("Downloading files...");
}
