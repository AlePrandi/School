let url = "./magazzino.json"; // url che punta al json... può essere anche un url sul web

clearForClass("caratteristiche");

let carat = document.getElementsByClassName("caratteristiche");
let card_container = document.getElementsByClassName("card-container")[0]; // Accesso corretto al primo elemento

fetch(url)
    .then(response => response.json()) // Richiamo la funzione json
    .then(dati => {
        const datiJson = dati;
        console.log(datiJson); // Stampo l'oggetto creato dall'importazione del json

        datiJson.forEach(riga => { // Scorro l'array di oggetti
            console.log(riga);
            let card = document.createElement('div');
            card.classList.add("card"); // Aggiungo la classe "card" per styling
            card.innerHTML = `
                <a class="card1" href="#">
                    <div class="caratteristiche">
                        <p>${riga.modelloNome}</p>
                        <p class="small">reparto: ${riga.reparto}<br>marca: ${riga.marca}</p>
                        <div class="go-corner" href="#">
                            <div class="go-arrow">→</div>
                        </div>
                    </div>
                </a>`;
            card_container.appendChild(card); // Appendo correttamente il nuovo elemento al container
        });

    });

function clearForClass(classe) {
    let elem = document.getElementsByClassName(classe);

    while (elem.length > 0) {
        elem[0].parentNode.removeChild(elem[0]);
    }
}