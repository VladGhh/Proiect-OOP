# Dark Souls: Varianta in Text

Un motor de joc de tip **Text-Based RPG** implementat în **C++**, inspirat din universul **Dark Souls**. Proiectul simulează mecanici de explorare, luptă pe ture, gestionare a inventarului și interacțiune cu NPC-uri, demonstrând utilizarea conceptelor fundamentale și avansate ale **Programării Orientate pe Obiecte (POO)**.

## Descriere Joc

Jucătorul preia rolul unui personaj care trebuie să exploreze o hartă interconectată, să învingă inamici și boși și să colecteze resurse pentru a supraviețui.

### Functionalitati Principale

* **Navigare:** Sistem de deplasare între camere bazat pe un graf (implementat prin liste de adiacență folosind vectori).
* **Sistem de Lupta:** Luptă pe ture contra inamicilor și a Boșilor, utilizând arme și obiecte ofensive.
* **Inventar:** Gestionarea obiectelor (arme, consumabile, chei) într-un container dinamic.
* **Leaderboard:** Sistem de clasament care memorează eroii câștigători și pe cei învinși, folosind structuri de date diferite pentru optimizare.
* **Mecanica Bonfire:** Puncte de control care refac viața jucătorului dar declanșează reînvierea (respawn-ul) inamicilor pe hartă.
* **Interactiuni:** Dialoguri cu NPC-uri și colectarea de obiecte din cufere.

---

## Implementare Tehnica (Cerinte POO)

Proiectul respectă cerințele laboratorului, implementând următoarele concepte:

### 1. Ierarhii de Clase
Au fost definite mai multe ierarhii și clase principale:
* **Ierarhia Entity**: Clasa de bază din care derivă `NPC` și `Character`.
* **Clasa Abstractă Character**: Clasă de bază abstractă (conține metoda pur virtuală `attack`) pentru `Player`, `Enemy` și `Boss`.
* **Ierarhia Item**: Clasa de bază pentru `Weapon`, `Consumable` și `KeyItem`.
* **Clasa Person**: Utilizată pentru gestionarea intrărilor în Leaderboard.
* **Ierarhia GameException**: Gestionarea erorilor proprii, derivată din `std::exception`.

### 2. Clase Template
* **Room<T>**: O clasă template generică ce permite instanțierea camerelor cu conținut variat (ex: `Room<Enemy*>`, `Room<NPC*>`, `Room<Consumable*>`). Aceasta demonstrează specializarea comportamentului metodei `visit()` în funcție de tipul entității din cameră.
* **Inventory<T>**: Clasa template responsabilă de stocarea și manipularea colecției de obiecte a jucătorului.

### 3. Supraincarcarea Operatorilor si Functii Friend
* **Operatorul <<:** A fost supraîncărcat pentru clasa `Person` pentru a permite afișarea directă la consolă.
* **Functii friend:** Au fost utilizate pentru a permite operatorului de afișare accesul la datele private ale claselor.
* **Operatorul = si Copy Constructor:** Implementate explicit în clasa `KeyItem` pentru a gestiona corect copierea obiectelor (Rule of Three).
* **Operatorul += (Functie Membra):** Supraîncărcat în clasa `Character` pentru a implementa mecanica de **Heal**. Permite modificarea directă a obiectului curent (`*this += amount`), demonstrând utilizarea unui operator membru care alterează starea internă.

### 4. Polimorfism, RTTI si Casting (Upcast & Downcast)
* **Upcasting:** Utilizat extensiv pentru tratarea uniformă a obiectelor derivate.
    * **Exemplu NPC:** NPC-urile dețin un pointer generic la clasa de bază `Item*` pentru cadouri. Acest pointer poate face referire la obiecte de tip `Weapon`, `Consumable` sau `KeyItem` fără a cunoaște tipul exact la compilare.
    * **Exemplu Inventar:** Containerul stochează pointeri `Item*`, permițând salvarea oricărui tip de obiect colectabil.
* **Downcasting si RTTI:** Utilizarea **dynamic_cast** pentru a recupera tipul specific al obiectelor la runtime.
    * În clasa `Player`: Se verifică dacă un `Item*` este `Consumable*` (pentru a fi folosit) sau `Weapon*` (pentru a fi echipat), asigurând Type Safety.
* **Functii Virtuale:** Metodele `attack`, `use` și `visit` sunt definite virtual pentru a asigura legarea dinamică (Late Binding).

### 5. Design Patterns
* **Trigger / Observer Mechanism:** Implementat pentru mecanica de **Bonfire**. Clasa `Room` acționează ca un declanșator care notifică clasa principală `Map` atunci când jucătorul se odihnește. Acest lucru permite decuplarea logicii camerei de logica globală a hărții.

### 6. STL (Standard Template Library)
* **std::vector**: Utilizat pentru stocarea inventarului, a listei de vecini și a listei câștigătorilor (`winBoard`).
* **std::list**: Utilizat pentru lista jucătorilor învinși (`loseBoard`) în Leaderboard, demonstrând utilizarea a două containere diferite.
* **Algoritmi si Lambda:** Utilizarea `std::sort` (pentru vector) și `list::sort` (pentru listă) împreună cu **funcții lambda** pentru sortarea clasamentului.

### 7. Gestiunea Resurselor si Exceptii
* Alocare dinamică a memoriei și implementarea destructorilor virtuali pentru evitarea memory leak-urilor.
* Utilizarea blocurilor **try-catch** pentru validarea input-ului utilizatorului și a acțiunilor critice.

### 8. Membri Statici
* Utilizarea membrilor statici pentru contorizarea instanțelor de boși activi în joc.

---


Proiectul este configurat folosind CMake.
