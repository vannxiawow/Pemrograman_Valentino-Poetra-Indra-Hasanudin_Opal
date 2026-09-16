#include <iostream>


bool isEven(int num) {
    return num % 2 == 0;
}

int main() {
    int N, K;
    
    std::cout << "========================================" << std::endl;
    std::cout << "           THE LAST ASTRONAUT       " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> N;
    std::cout << "Masukkan nilai K awal: ";
    std::cin >> K;
    
    
    if (N <= 0 || K < 2) {
        std::cout << "Input tidak valid N harus > 0 dan K harus >= 2." << std::endl;
        return 1;
    }
    
    
    int* astronot = new int[N];
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }
    
    std::cout << "\nUrutan Astronot yang Dieliminasi:" << std::endl;
    
    int activeCount = N;
    int currentIndex = 0;
    
    
    while (activeCount > 1) {
        int steps = 0;
        
 
        while (steps < K - 1) {
            if (astronot[currentIndex] != 0) {
                steps++;
            }
            currentIndex = (currentIndex + 1) % N;
        }
        

        while (astronot[currentIndex] == 0) {
            currentIndex = (currentIndex + 1) % N;
        }
        

        int eliminated = astronot[currentIndex];
        std::cout << "- Astronot " << eliminated << " (K lama = " << K;
        
        astronot[currentIndex] = 0; 
        activeCount--;
        
      
        if (isEven(eliminated)) {
            K += 2; // Genap: K + 2
        } else {
            K -= 1; // Ganjil: K - 1
        }
        
       
        if (K < 2) {
            K = 2;
        }
        
        std::cout << ", K baru = " << K << ")" << std::endl;
        
        // Pindah ke astronot aktif berikutnya jika permainan belum selesai
        if (activeCount > 1) {
            do {
                currentIndex = (currentIndex + 1) % N;
            } while (astronot[currentIndex] == 0);
        }
    }
    
    // Cari astronot terakhir yang tersisa
    std::cout << "\n========================================" << std::endl;
    for (int i = 0; i < N; i++) {
        if (astronot[i] != 0) {
            std::cout << "Astronot Terakhir yang Bertahan: Astronot " << astronot[i] << std::endl;
            break;
        }
    }
    std::cout << "========================================" << std::endl;
    
    // Dealokasi memori
    delete[] astronot;
    return 0;
}
