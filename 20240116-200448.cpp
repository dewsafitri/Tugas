class Mobil:
    def __init__(self, merk, harga, stok):
        self.merk = merk
        self.harga = harga
        self.stok = stok

    def tampilkan_info(self):
        print(f"Merk: {self.merk}, Harga: {self.harga} USD, Stok: {self.stok} unit")

def beli_mobil(mobil, jumlah):
    if mobil.stok >= jumlah:
        total_harga = mobil.harga * jumlah
        mobil.stok -= jumlah
        return f"Anda telah membeli {jumlah} unit {mobil.merk}. Total harga: {total_harga} USD."
    else:
        return f"Maaf, stok {mobil.merk} tidak mencukupi untuk pembelian ini."

def main():
    daftar_mobil = [
        Mobil("Toyota", 25000, 10),
        Mobil("Honda", 22000, 15),
        Mobil("Ford", 28000, 8),
        Mobil("daihatsu" , 300, 10),
        Mobil("suzuki",400 , 15),
        Mobil("kia", 500 , 60),
        Mobil("cerry", 200, 50),
        Mobil("nissan",4000, 35)
    ]

    while True:
        print("\nMenu:")
        print("1. Tampilkan Mobil")
        print("2. Beli Mobil")
        print("3. Keluar")

        pilihan = input("Pilih menu (1/2/3): ")

        if pilihan == "1":
            print("\nDaftar Mobil:")
            for mobil in daftar_mobil:
                mobil.tampilkan_info()
        elif pilihan == "2":
            merk_mobil = input("Masukkan merk mobil yang ingin dibeli: ")
            mobil_terpilih = next((mobil for mobil in daftar_mobil if mobil.merk.lower() == merk_mobil.lower()), None)

            if mobil_terpilih:
                jumlah_pembelian = int(input(f"Masukkan jumlah {mobil_terpilih.merk} yang ingin dibeli: "))
                hasil_pembelian = beli_mobil(mobil_terpilih, jumlah_pembelian)
                print(hasil_pembelian)
            else:
                print("Merk mobil tidak ditemukan.")
        elif pilihan == "3":
            print("Terima kasih! Keluar dari program.")
            break
        else:
            print("Pilihan tidak valid. Silakan pilih menu yang benar.")

if __name__ == "__main__":
    main()