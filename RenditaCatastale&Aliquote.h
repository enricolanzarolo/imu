float fbi(int categoria, float renditacatastale)
{
    float baseimponibile = 0;
    int moltiplicatore = 0;

    if((categoria > 0) && (categoria < 11) && (categoria != 9))              //categoria A senza A/10
    {
        moltiplicatore = 160;
    }
    else if(categoria == 9)
    {
        moltiplicatore = 80;
    }
    else if(categoria == 11)
    {
        moltiplicatore = 55;
    }
    else if((categoria == 12) || (categoria == 16) || (categoria == 17))
    {
        moltiplicatore = 160;
    }
    else if((categoria == 13) || (categoria == 14) || (categoria == 15))
    {
        moltiplicatore = 140;
    }

    baseimponibile = renditacatastale * moltiplicatore;
    return baseimponibile;
}

float alilegnago(int cat, int principale, int cata, int catc,int *detrazione)           //https://www.comune.legnago.vr.it/c023044/zf/index.php/servizi-aggiuntivi/index/index/idtesto/510
{
    if((principale == 1) && ((cat == 1) || (cat == 7) || (cat == 8) || (cat == 12) || (cat == 16) || (cat == 17)))
    return 6;

    else if(cata < 3)
    {
        if((principale == 0) && (((cat > 0) && (cat <= 9)) || (cat == 10) || (cat == 12) || (cat == 16) || (cat == 17)))
        return 9.90;
    }
    else if(catc >= 3)
    {
        return 10.60;
    }
    else if(cata >= 3)
    {
        if((principale == 0) && (((cat>0) && (cat <= 9)) || (cat == 10) || (cat == 12) || (cat == 16) || (cat == 17)))
        return 10.60;
    }
    else if(cat == 10){
       return 9.90;
	}
    else if(cat == 11){
        return 8.30;
	}
	else if(cat == 13){
        return 8;
	}
    else if((cat == 14) || (cat == 15)){
        return 8.50;
    }
}

float alicerea(int cat, int principale, int cata, int catc, int *detrazione) //https://www.cerea.net/c023025/images/ALIQUOTE%20IMU%202023.pdf
{
    if((principale == 1) && ((cat == 1) || (cat == 7) || (cat == 8) || (cat == 12) || (cat == 16) || (cat == 17))){
        *detrazione = 200;        //sottraggo 200 euro dopo
        return 6;
    }
    else
        return 10.40;
}

float aliandrano(int cat, int principale, int cata, int catc, int *detrazione)   //https://www.comune.andrano.le.it/amministrazione/ente/organigramma/item/ufficio-tributi-imu.html
{
    if((principale == 1)&&((cat == 1) || (cat == 7) || (cat == 8))){
        *detrazione = 200;
        return 6;
    }
    else
        return 10.60;
}

float alilecce(int cat, int principale, int cata, int catc, int *detrazione) //https://www.comune.lecce.it/aree-tematiche/tasse/servizi-comunali/imu---imposta-municipale-unica/aliquote-imu-fissate-dal-comune---anno-2023
{
    if((principale == 1)&&((cat == 1) || (cat == 7) || (cat == 8) || (cat == 12) || (cat == 16) || (cat == 17))){
        *detrazione = 200;
        return 6;
    }
    else if(cat == 4){  //per le case popolari detrazione 200 euro a lecce
        *detrazione = 200;
    return 1.10;
    }
    else
        return 1.10;
}

float alisola(int cat, int principale, int cata, int catc, int *detrazione) //https://comune.isoladellascala.vr.it/Servizi?ID=114329
{
     if((principale == 1)&&((cat == 1) || (cat == 7) || (cat == 8) || (cat == 12) || (cat == 16) || (cat == 17))){
        *detrazione=200;
        return 6;
     }

    else if((principale == 0) && (((cat >= 1) && (cat < 9)) || (cat == 12) || (cat == 16) || (cat == 17)))
        return 10.60;

    else if((cat == 13) || (cat == 14) || (cat == 15))
        return 8.10;

    else if(cat == 9)
        return 10.60;

    else if(cat == 11)
        return 8.10;

    else
        return 5;
}

