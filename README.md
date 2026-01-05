# Dark Souls: Varianta in Text

Un motor de joc de tip **Text-Based RPG** implementat în **C++**, inspirat din universul **Dark Souls**. Proiectul simulează mecanici de explorare, luptă pe ture, gestionare a inventarului și interacțiune cu NPC-uri, demonstrând utilizarea conceptelor fundamentale și avansate ale **Programării Orientate pe Obiecte (POO)**.

## Descriere Joc

Jucătorul preia rolul unui personaj care trebuie să exploreze o hartă interconectată, să învingă inamici și boși și să colecteze resurse pentru a supraviețui.

### Functionalitati Principale

* **Navigare:** Sistem de deplasare între camere bazat pe un graf (implementat prin liste de adiacență folosind vectori).
* **Sistem de Lupta:** Luptă pe ture contra inamicilor și a Boșilor, utilizând arme și obiecte ofensive.
* **Inventar:** Gestionarea obiectelor (arme, consumabile, chei) într-un container dinamic.
* **Leaderboard:** Sistem de clasament care memorează eroii câștigători și pe cei învinși.
* **Mecanica Bonfire:** Puncte de control care refac viața jucătorului dar declanșează reînvierea (respawn-ul) inamicilor pe hartă.
* **Interactiuni:** Dialoguri cu NPC-uri și colectarea de obiecte din cufere.

---

## Implementare Tehnica (Cerinte POO)

Proiectul respectă cerințele laboratorului, implementând următoarele concepte:

### 1. Ierarhii de Clase
Au fost definite mai multe ierarhii și clase principale:
* **Ierarhia Entity**: Clasa de bază abstractă pentru `Player`, `Enemy`, `Boss` și `NPC`.
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

### 4. Polimorfism si RTTI
* Utilizarea **funcțiilor virtuale** (`attack`, `use`, `visit`) pentru comportament polimorfic la rulare.
* Utilizarea **dynamic_cast (RTTI)** pentru a determina tipul exact al obiectelor la runtime (de exemplu, verificarea dacă un `Item` este `Weapon` sau `Consumable` înainte de utilizare).

### 5. Gestiunea Resurselor si Memoriei
* Alocare dinamică a memoriei pentru entități și camere.
* Implementarea destructorilor (inclusiv **destructori virtuali** în clasele de bază) pentru a asigura eliberarea corectă a memoriei și evitarea memory leak-urilor (`~Map`, `~Player`, `~Room`).

### 6. Exceptii
* Definirea unei ierarhii proprii de excepții (`GameException`, `InvalidItemException`, `InvalidChoice`).
* Utilizarea blocurilor **try-catch** pentru validarea input-ului utilizatorului și a acțiunilor critice.

### 7. STL (Standard Template Library)
* **std::vector**: Utilizat extensiv pentru stocarea inventarului, a listei de vecini pentru fiecare cameră și pentru structura hărții.
* **Algoritmi si Lambda:** Utilizarea `std::sort` împreună cu **funcții lambda** în cadrul clasei `Inventory` pentru sortarea obiectelor.

### 8. Membri Statici
* Utilizarea membrilor statici pentru contorizarea instanțelor de boși activi în joc.

---

Proiectul este configurat folosind CMake.
