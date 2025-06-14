# Programowanie-obiektowe-projekt-ko-cowy

## Opis Projektu

Ten projekt stanowi końcowy projekt z kursu Programowania Obiektowego, mający na celu praktyczne zademonstrowanie kluczowych zasad i technik OOP w języku C++. Jest to implementacja **graficznego menedżera zadań**, zaprojektowanego, aby pomóc użytkownikom w efektywnym zarządzaniu codziennymi obowiązkami i wydarzeniami. Aplikacja wykorzystuje bibliotekę Qt do stworzenia intuicyjnego interfejsu graficznego, umożliwiając łatwe dodawanie, edytowanie, usuwanie i oznaczanie zadań. Projekt ilustruje zastosowanie klas i obiektów do modelowania rzeczywistych bytów (np. `Task`), hermetyzacji danych oraz organizacji kodu w modułowy i czytelny sposób. Użytkownicy mogą przypisywać zadaniom konkretne terminy, a system automatycznie powiadamia o zbliżających się lub minionych deadline'ach, niektóre wrażliwe funkcje są dodatkowo chronione hasłem administratora, co stanowi przykład prostego mechanizmu kontroli dostępu.

## Technologie

Projekt został zaimplementowany w języku C++ z wykorzystaniem potężnej i wszechstronnej biblioteki **Qt** (konkretnie modułu Qt Widgets) do stworzenia interfejsu graficznego. Wybór Qt gwarantuje przenośność aplikacji między różnymi systemami operacyjnymi.

* **Język:** C++ – Wykorzystuje nowoczesne cechy języka C++ dla czystego i efektywnego kodu.

* **Framework GUI:** Qt (Qt Widgets) – Użyty do budowy graficznego interfejsu użytkownika, zapewniający bogaty zestaw gotowych komponentów UI (np. kalendarz, listy, przyciski, okna dialogowe).

* **Standard C++:** Projekt korzysta z nowoczesnych funkcji C++ (prawdopodobnie C++11/C++14/C++17), co pozwala na wykorzystanie takich elementów jak lambdy, `auto` i inne usprawnienia języka.

* **Kompilator:** Dowolny kompilator zgodny ze standardem C++ i Qt, np. g++ (GNU C++ Compiler) na Linux/macOS, Clang, lub MSVC (Microsoft Visual C++) na Windowsie.

## Struktura Projektu

Repozytorium zawiera następujące kluczowe pliki i katalogi, zorganizowane w logiczną strukturę:

* `main.cpp`: Główny punkt wejścia do aplikacji. Odpowiada za inicjalizację aplikacji Qt (`QApplication`) i stworzenie oraz wyświetlenie głównego okna programu (`MainWindow`).

* `mainwindow.h`, `mainwindow.cpp`: Te pliki zawierają definicję (`.h`) i implementację (`.cpp`) klasy `MainWindow`. `MainWindow` jest sercem interfejsu użytkownika, zarządzając układem okna, logiką obsługi zdarzeń (np. kliknięcia przycisków, zmiany daty w kalendarzu) i aktualizacją widoku zadań.

* `mainwindow.ui`: Jest to plik XML generowany przez Qt Designer, wizualne narzędzie do projektowania GUI. Definiuje on układ graficzny głównego okna, rozmieszczenie widżetów (kalendarz, lista zadań, przyciski) oraz ich początkowe właściwości.

* `Task.h`, `task.cpp`: Klasa `Task` jest modelem danych dla pojedynczego zadania. Pliki te definiują (`.h`) i implementują (`.cpp`) tę klasę, zawierającą pola takie jak `m_text` (treść zadania), `m_deadline` (termin), `m_done` (status wykonania) oraz `m_overdue` (czy zadanie jest zaległe). Klasa ta posiada również metody dostępowe (gettery i settery) oraz metodę `toString()` do formatowania wyświetlanej treści zadania.

* `datetime_dialog.h`, `datetime.cpp`: Klasa `DateTimeDialog` to niestandardowe okno dialogowe, które pozwala użytkownikowi wybrać konkretną datę i godzinę dla terminu zadania. Jest to oddzielny komponent GUI, promujący modularność kodu.

* `ui_mainwindow.h`: Jest to plik nagłówkowy automatycznie generowany przez narzędzie `uic` (Qt User Interface Compiler) z pliku `mainwindow.ui`. Zawiera on definicje klas i metod, które pozwalają na dostęp do elementów interfejsu użytkownika z kodu C++.

## Kompilacja i Uruchomienie

Aby skompilować i uruchomić ten projekt, potrzebujesz odpowiedniego środowiska deweloperskiego C++ z zainstalowanymi bibliotekami Qt. Zaleca się użycie `qmake` (narzędzie do zarządzania projektami Qt) lub `CMake` do ułatwienia procesu kompilacji.

### Wymagania

* **Qt SDK:** Zainstalowane Qt SDK (zalecana wersja 5.x lub 6.x) odpowiednia dla Twojego systemu operacyjnego. Qt SDK zawiera `qmake` oraz inne niezbędne narzędzia i biblioteki.

* **Kompilator C++:**

    * **Na Linux/macOS:** Standardowy `g++` lub Clang, dostępny poprzez menedżer pakietów systemowych.

    * **Na Windowsie:**

        * **MinGW/MSYS2:** Wolny i otwarty kompilator GCC z narzędziami Unix-like. Często dołączany do instalacji Qt.

        * **Visual Studio z narzędziami C++:** Upewnij się, że masz zainstalowany pakiet "Programowanie klasycznych aplikacji w C++" podczas instalacji Visual Studio.

* **System operacyjny:** Aplikacja jest przenośna i powinna działać na systemach Windows, macOS oraz Linux.

### Kroki Kompilacji (przykład z qmake)

Poniższe kroki zakładają, że masz zainstalowane Qt SDK i odpowiednie narzędzia w ścieżce systemowej.

1.  **Sklonuj repozytorium:**
    Otwórz terminal (Linux/macOS) lub wiersz poleceń/PowerShell (Windows) i wykonaj komendę:

    ```bash
    git clone [https://github.com/277601/Programowanie-obiektowe-projekt-ko-cowy.git](https://github.com/277601/Programowanie-obiektowe-projekt-ko-cowy.git)
    ```

2.  **Przejdź do katalogu projektu:**

    ```bash
    cd Programowanie-obiektowe-projekt-ko-cowy
    ```

3.  **Utwórz plik projektu Qt (`.pro`), jeśli go nie ma, lub użyj istniejącego:**
    Projekt Qt zazwyczaj posiada plik z rozszerzeniem `.pro` (np. `Programowanie-obiektowe-projekt-ko-cowy.pro`), który definiuje strukturę projektu dla `qmake`. Jeśli go nie ma, należy go utworzyć ręcznie lub za pomocą Qt Creator. Poniżej znajduje się typowa zawartość takiego pliku dla tego projektu:

    ```pro
    QT       += widgets

    SOURCES += \
        main.cpp \
        mainwindow.cpp \
        datetime.cpp \
        task.cpp

    HEADERS += \
        mainwindow.h \
        datetime_dialog.h \
        Task.h

    FORMS += \
        mainwindow.ui

    CONFIG += c++17 # Upewnij się, że standard C++ odpowiada temu, co jest użyte w kodzie
    ```

    *(Upewnij się, że wszystkie pliki `.cpp`, `.h` i `.ui` są poprawnie wymienione w tym pliku. Jeśli plik `.pro` już istnieje w repozytorium, po prostu go użyj.)*

4.  **Wygeneruj plik Makefile za pomocą `qmake`:**
    W katalogu projektu, gdzie znajduje się plik `.pro`, wykonaj:

    ```bash
    qmake TwójProjekt.pro # Zastąp 'TwójProjekt.pro' rzeczywistą nazwą pliku .pro
    ```

    To polecenie wygeneruje pliki Makefile (lub pliki projektu Visual Studio na Windowsie), które są niezbędne do kompilacji.

5.  **Skompiluj projekt za pomocą `make`:**

    ```bash
    make
    ```

    * **Na Linux/macOS:** Użyj komendy `make`.

    * **Na Windowsie (MinGW/MSYS2):** Użyj `mingw32-make`.

    * **Na Windowsie (Visual Studio Command Prompt):** Użyj `nmake`.

### Uruchomienie

Po udanej kompilacji, program wykonywalny zostanie utworzony w katalogu projektu (lub podkatalogu takim jak `debug`/`release`, w zależności od konfiguracji kompilacji).

* **Na Linux/macOS:**
    Otwórz terminal w katalogu, gdzie znajduje się plik wykonywalny i uruchom:

    ```bash
    ./nazwa_programu_wykonywalnego
    ```

    (np. `./Programowanie-obiektowe-projekt-ko-cowy`)

* **Na Windowsie (w wierszu poleceń/PowerShell):**
    Przejdź do katalogu z plikiem wykonywalnym i uruchom:

    ```bash
    nazwa_programu_wykonywalnego.exe
    ```

    (np. `Programowanie-obiektowe-projekt-ko-cowy.exe`)

## Użycie Programu

Aplikacja "Menedżer Zadań" zapewnia intuicyjny interfejs graficzny do zarządzania Twoimi zadaniami. Oto szczegółowy przewodnik po jej funkcjach:

1.  **Główne okno aplikacji:** Po uruchomieniu, interfejs składa się z widżetu kalendarza (`QCalendarWidget`) po lewej stronie, dużego pola listy zadań (`QListWidget`) po prawej, oraz zestawu przycisków akcji umieszczonych pod listą zadań. Okno ma stały rozmiar 800x600 pikseli.

2.  **Wybór daty:** Kliknięcie na dowolną datę w kalendarzu spowoduje odświeżenie listy zadań po prawej stronie, wyświetlając tylko te zadania, które są przypisane do wybranego dnia.

3.  **Dodawanie zadań:**

    * Kliknij przycisk **"Dodaj zadanie"**.

    * Pojawi się okno dialogowe (`QInputDialog`) z prośbą o wprowadzenie treści nowego zadania. Wpisz krótki opis, np. "Przygotować prezentację na OOP".

    * Następnie otworzy się dedykowane okno wyboru daty i godziny (`DateTimeDialog`), gdzie możesz precyzyjnie ustawić termin (dzień, miesiąc, rok, godzinę i minutę) dla Twojego zadania. Po zatwierdzeniu zadanie zostanie dodane do listy na odpowiednią datę.

4.  **Edycja zadań:**

    * Zaznacz istniejące zadanie na liście, klikając na nie.

    * Kliknij przycisk **"Edytuj zadanie"**.

    * Otworzy się okno dialogowe z obecną treścią zadania, którą możesz zmodyfikować. Po potwierdzeniu zmiana zostanie zapisana.

5.  **Usuwanie zadań:**

    * Zaznacz zadanie, które chcesz usunąć z listy.

    * Kliknij przycisk **"Usuń zadanie"**.

    * Dla bezpieczeństwa, pojawi się okno dialogowe z prośbą o podanie hasła administratora. **Domyślne hasło to "1108"**. Po poprawnym podaniu hasła zadanie zostanie trwale usunięte z listy.

6.  **Oznaczanie zadań jako wykonane:**

    * Wybierz zadanie z listy, które zostało ukończone.

    * Kliknij przycisk **"Odznacz jako wykonane"**. Wybrane zadanie zostanie wizualnie oznaczone symbolem ✅ (zielony znacznik wyboru) na początku jego tekstu, a sam tekst zostanie wyszarzony, co ułatwia odróżnienie wykonanych zadań.

7.  **Oznaczanie dni wolnych:**

    * Wybierz w kalendarzu dzień, który chcesz oznaczyć jako "wolny" lub specjalny.

    * Kliknij przycisk **"Dni wolne"**.

    * Podobnie jak przy usuwaniu, zostaniesz poproszony o hasło administratora. **Domyślne hasło dla tej funkcji to "2137"**. Po poprawnym podaniu hasła, wybrany dzień w kalendarzu zostanie podświetlony na jasnoniebiesko i pogrubiony, co wizualnie wyróżnia go jako dzień wolny.

8.  **Powiadomienia o terminach:** Aplikacja posiada wbudowany mechanizm sprawdzający terminy zadań. Co 10 sekund aplikacja weryfikuje wszystkie aktywne zadania.

    * Jeśli termin jakiegoś zadania minął, a zadanie nie zostało jeszcze oznaczone jako wykonane, pojawi się okno dialogowe (`QMessageBox`) z informacją o zaległym zadaniu i pytaniem: "Czy zostało wykonane?".

    * Jeśli wybierzesz "Tak", zostaniesz poproszony o podanie hasła administratora (**"1108"**). Masz trzy próby. Po trzech nieudanych próbach lub wybraniu "Nie" w pytaniu, zadanie zostanie trwale oznaczone symbolem ❌ (czerwony krzyżyk), wskazując, że jest zaległe i nie zostało zweryfikowane.

9.  **Widok zadań na liście:** Każde zadanie na liście jest formatowane w następujący sposób: `[status] [termin] [treść zadania]`.

    * ✅: Zadanie zostało wykonane.

    * ❌: Zadanie jest zaległe (termin minął i nie zostało zweryfikowane hasłem).

    * 🕒: Zadanie jest aktywne i oczekuje na wykonanie (termin jeszcze nie minął).

    * `[termin]` jest wyświetlany w formacie `DD.MM.RRRR HH:MM`.

10. **Opcje (Ustawienia):** W pasku menu na górze okna (jeśli jest widoczny `QMenuBar` i `actionSettings`) znajduje się opcja "Opcje", która obecnie wyświetla jedynie prosty komunikat informacyjny. W przyszłości można by tam dodać zaawansowane ustawienia aplikacji.

## Funkcjonalności

Aplikacja "Menedżer Zadań" oferuje następujące kluczowe funkcje, demonstrujące zasady programowania obiektowego i obsługę GUI:

* **Kompleksowe zarządzanie zadaniami:**

    * **Dodawanie:** Umożliwia tworzenie nowych zadań z elastycznym przypisywaniem treści i precyzyjnych terminów (data i godzina).

    * **Edycja:** Pozwala na modyfikację treści istniejących zadań, ułatwiając utrzymanie aktualności harmonogramu.

    * **Usuwanie:** Funkcja kasowania zadań, która dla bezpieczeństwa wymaga podania hasła administratora, zapobiegając przypadkowemu usunięciu ważnych pozycji.

    * **Oznaczanie wykonania:** Prosty mechanizm oznaczania zadań jako ukończonych, z wizualnym potwierdzeniem (znacznik ✅ i wyszarzenie tekstu).

    * *Uwaga: Obecna wersja aplikacji nie implementuje trwałego przechowywania danych. Zadania są przechowywane tylko w pamięci (w `QMap<QDate, QList<Task>> tasks`) i resetują się po zamknięciu programu. Do przyszłego rozwoju można by dodać obsługę plików (np. CSV, JSON) lub bazy danych.*

* **Interaktywny kalendarz:**

    * **Wizualny przegląd:** Integracja widżetu kalendarza ułatwia nawigację po datach i przeglądanie zadań przypisanych do konkretnych dni.

    * **Oznaczanie dni specjalnych:** Funkcja oznaczania dni jako "wolnych" (chroniona hasłem), co pozwala na wizualne wyróżnienie dni wolnych od pracy/zadań w kalendarzu.

* **System powiadomień o terminach:**

    * **Automatyczne monitorowanie:** Aplikacja w tle cyklicznie sprawdza terminy wszystkich zadań.

    * **Powiadomienia o zaległościach:** W przypadku minionego terminu zadania, użytkownik otrzymuje powiadomienie, które wymaga interakcji i weryfikacji hasłem, aby potwierdzić wykonanie lub oznaczyć zadanie jako zaległe.

* **Weryfikacja hasłem:** Wprowadzono prosty mechanizm uwierzytelniania hasłem (`"1108"` i `"2137"`) dla wrażliwych operacji, takich jak usuwanie zadań, oznaczanie dni wolnych i potwierdzanie zaległych zadań. Demonstruje to podstawowe zastosowanie kontroli dostępu.

* **Wizualny status zadań:** Zadania na liście są jasno oznaczone graficznymi symbolami (✅, ❌, 🕒) oraz sformatowanym terminem, co pozwala na szybkie zorientowanie się w ich statusie i priorytecie.

## Licencja

Ten projekt jest udostępniany na licencji \[**MIT License** \]. Licencja MIT jest popularną, liberalną licencją open source, która pozwala na szerokie wykorzystanie kodu, pod warunkiem zachowania informacji o oryginalnej licencji i autorach.

## Autor

**Karol Kościelski 277601**

* [Profil GitHub](https://github.com/277601)
