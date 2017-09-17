#include <gif_lib.h>
#include <iostream>
#include <string>

int main(){
    GifFileType* gif2 = DGifOpenFileName("generated4.gif");
    
    if (gif2 == NULL) {
        std::cout << "Failed to open .gif, return error with type " << std::endl;
        return false;
    }
    
    int slurpReturn2 = DGifSlurp(gif2);
    if (slurpReturn2 != GIF_OK) {
        std::cout << "Failed to read .gif file" << std::endl;
        return false;
    }
    
    int messageSize = gif2->SavedImages[0].ImageDesc.ColorMap->Colors[0].Red +
                        gif2->SavedImages[0].ImageDesc.ColorMap->Colors[0].Green;
    
    std::string message = "";
    for(int i = 0; i < messageSize; i++){
        message += gif2->SavedImages[1].ImageDesc.ColorMap->Colors[i].Blue;
    }
    std::cout << message << std::endl;
    
    return 0;
}