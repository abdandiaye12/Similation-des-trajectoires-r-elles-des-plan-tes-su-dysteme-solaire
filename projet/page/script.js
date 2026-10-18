let echelle = 800000000;
let taillePlanetes = 0.7;

let dataJSON;
let Planetes = [];
let mouvement = 0;
let a = 0;
let speed = 1;

let centre_hauteur;
let centre_largeur;

let imgSoleil;
let imgTerre;
let imgMars;
let imgVenus;

let texteVitesse = "";
let timerVitesse = 0;

function preload() {
  imgSoleil = loadImage("./images/soleil.png");
  imgTerre = loadImage("./images/terre.png");
  imgMars = loadImage("./images/mars.png");
  imgVenus = loadImage("./images/venus.png");

  let btnRalenti = createButton("◀◀");
  btnRalenti.parent("menu");
  btnRalenti.mousePressed(ralenti);
  
  let btnLancer = createButton("▶");
  btnLancer.parent("menu");
  btnLancer.mousePressed(lancer);

  let btnPause = createButton("❚❚");
  btnPause.parent("menu");
  btnPause.mousePressed(pause);

  let btnAccel = createButton("▶▶");
  btnAccel.parent("menu");
  btnAccel.mousePressed(accelerer); 
  
  let btnReset = createButton("⏹");
  btnReset.parent("menu");
  btnReset.mousePressed(reset);
}

function readFile(input) {
  let file = input.files[0];
  let reader = new FileReader();

  reader.readAsText(file);

  reader.onload = function() {
    dataJSON = JSON.parse(reader.result);
    Planetes = Object.keys(dataJSON);
    
    a = 0;
    mouvement = 0;
    
    image(imgSoleil, centre_largeur, centre_hauteur, 150*taillePlanetes, 150*taillePlanetes);
    
    for (let p = 0; p < Planetes.length; p++){
      let planete = Planetes[p];

      if (planete === "Terre") stroke(0, 100, 250);
      else if (planete === "Mars") stroke(255, 50, 50);
      else if (planete === "Venus") stroke(255, 200, 50);
      else stroke(255);

      for(let i = 0; i < dataJSON[planete].length; i++){
        point(centre_largeur + dataJSON[planete][i][0][0] / echelle, centre_hauteur + dataJSON[planete][i][0][1] / echelle);
      }
      
      if (planete === "Terre") image(imgTerre, centre_largeur + dataJSON[planete][0][0][0] / echelle, centre_hauteur + dataJSON[planete][0][0][1] / echelle, 50*taillePlanetes, 50*taillePlanetes);
      else if (planete === "Mars") image(imgMars, centre_largeur + dataJSON[planete][0][0][0] / echelle, centre_hauteur + dataJSON[planete][0][0][1] / echelle, 26*taillePlanetes, 26*taillePlanetes);
      else if (planete === "Venus") image(imgVenus, centre_largeur + dataJSON[planete][0][0][0] / echelle, centre_hauteur + dataJSON[planete][0][0][1] / echelle, 47*taillePlanetes, 47*taillePlanetes);
    }
  };

  reader.onerror = function() {
    console.log(reader.error);
  };
}

function lancer() {
  mouvement = 1;
}

function pause(){
  mouvement = 0;
}

function reset(){
  a = 0;
  mouvement = 0;
  
  clear();

  if (dataJSON && Planetes.length > 0) {
    
    
    image(imgSoleil, centre_largeur, centre_hauteur, 150 * taillePlanetes, 150*taillePlanetes);
    
    for(let p = 0; p < Planetes.length; p++){
      let planete = Planetes[p];
      
      if (planete === "Terre") 
        stroke(0, 100, 250);
      else if (planete === "Mars") 
        stroke(255, 50, 50);
      else if (planete === "Venus") 
        stroke(255, 200, 50);
      else stroke(255);

      for(let i = 0; i < dataJSON[planete].length; i ++){
        point(centre_largeur + dataJSON[planete][i][0][0] / echelle, centre_hauteur + dataJSON[planete][i][0][1] / echelle);
      }
      
      if (planete === "Terre") 
        image(imgTerre, centre_largeur + dataJSON[planete][0][0][0] / echelle, centre_hauteur + dataJSON[planete][0][0][1] / echelle, 50*taillePlanetes, 50*taillePlanetes);
      else if (planete === "Mars") 
        image(imgMars, centre_largeur + dataJSON[planete][0][0][0] / echelle, centre_hauteur + dataJSON[planete][0][0][1] / echelle, 26*taillePlanetes, 26*taillePlanetes);
      else if (planete === "Venus") 
        image(imgVenus, centre_largeur + dataJSON[planete][0][0][0] / echelle, centre_hauteur + dataJSON[planete][0][0][1] / echelle, 47*taillePlanetes, 47*taillePlanetes);
    }
  }
}

function accelerer(){
  if (speed < 512) speed = speed*2;
  texteVitesse = "x" + speed;
  timerVitesse = 120;
}

function ralenti(){
  if (speed > 1) speed = speed / 2;
  texteVitesse = "x" + speed;
  timerVitesse = 120;
}

function setup() {
  createCanvas(windowWidth, windowHeight);
  imageMode(CENTER);
  
  centre_largeur = windowWidth / 2;
  centre_hauteur = windowHeight / 2;
  
  image(imgSoleil, centre_largeur, centre_hauteur, 150*taillePlanetes, 150*taillePlanetes); 
}

function draw() {
  if (mouvement === 1 && dataJSON && Planetes.length > 0) {
    
    clear();

    image(imgSoleil, centre_largeur, centre_hauteur, 150*taillePlanetes, 150*taillePlanetes);
    
    for(let p = 0; p < Planetes.length; p++){
      let planete = Planetes[p];

      if (planete === "Terre") stroke(0, 100, 250);
      else if (planete === "Mars") stroke(255, 50, 50);
      else if (planete === "Venus") stroke(255, 200, 50);
      else stroke(255);

      for(let i = 0; i < dataJSON[planete].length; i++){
        point(centre_largeur + dataJSON[planete][i][0][0] / echelle, centre_hauteur + dataJSON[planete][i][0][1] / echelle);
      }
      
      let indexTerre = a % dataJSON["Terre"].length;
      let indexMars = a % dataJSON["Mars"].length;
      let indexVenus = a % dataJSON["Venus"].length;

      if (planete === "Terre") image(imgTerre, centre_largeur + dataJSON[planete][indexTerre][0][0] / echelle, centre_hauteur + dataJSON[planete][indexTerre][0][1] / echelle, 50*taillePlanetes, 50*taillePlanetes);
      else if (planete === "Mars") image(imgMars, centre_largeur + dataJSON[planete][indexMars][0][0] / echelle, centre_hauteur + dataJSON[planete][indexMars][0][1] / echelle, 26*taillePlanetes, 26*taillePlanetes);
      else if (planete === "Venus") image(imgVenus, centre_largeur + dataJSON[planete][indexVenus][0][0] / echelle, centre_hauteur + dataJSON[planete][indexVenus][0][1] / echelle, 47*taillePlanetes, 47*taillePlanetes);
    }
    
    a = (a + speed); // on avance d'un pas
    
    if (timerVitesse != 0){
      fill(255, 255, 255, timerVitesse * 4);
      noStroke();
      textSize(20);
      textAlign(CENTER);
      text(texteVitesse, mouseX, (mouseY + 80));
      timerVitesse --;
    }
  }
}