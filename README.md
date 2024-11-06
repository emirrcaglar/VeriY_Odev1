# DNA İşlemleri Programı

Bu proje, MinGW C++ ortamında geliştirilen ve bağlı listeler kullanarak gen, kromozom ve DNA işlemleri yapabilen bir programdır. `Dna.txt` dosyasındaki veriler işlenerek genetik çaprazlama, mutasyon ve otomatik işlemler gerçekleştirilir.

## Proje İçeriği

Bu proje, aşağıdaki işlemleri desteklemektedir:

1. **Çaprazlama (Crossing Over)**: Kullanıcıdan iki kromozomun satır numarası alınır ve bu iki kromozom belirli kurallara göre birleştirilerek yeni kromozomlar oluşturulur. Yeni kromozomlar popülasyona eklenir.
   
2. **Mutasyon (Mutation)**: Kullanıcının seçtiği bir kromozom ve gen konumunda mutasyon yapılır, seçilen gen "X" karakterine dönüştürülür.

3. **Otomatik İşlemler**: `Islemler.txt` dosyasındaki işlemler sırasıyla uygulanır ve ekrana "işlem tamamlandı" mesajı yazılır.

4. **Ekrana Yaz (Display)**: Kromozomlar belirli bir kritere göre sağdan sola giderek ekrana yazdırılır.

5. **Çıkış**: Programdan çıkış yapılır.

## Dosya Yapısı

Projede aşağıdaki klasör yapısı kullanılmalıdır:

- `src/` - Kaynak dosyalar
- `lib/` - .o dosyaları
- `include/` - Başlık dosyaları
- `doc/` - Rapor dosyası
- `bin/` - Çalıştırılabilir (.exe) dosyalar
- `benioku.txt` - Program hakkında ek açıklamalar
- `makefile` - Derleme dosyası (makefile olmaması durumunda -50 puan ceza uygulanacaktır)
