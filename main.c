#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define GRID_SIZE 10
#define CELL_SIZE (WINDOW_HEIGHT / GRID_SIZE)



//*VALUES STRUCTS*********

//---------UNIT TYPES-------------
//$$$$$$$$$$-INSAN-$$$$$$$$$$$$$$$
struct Piyade {
    float saldiri;
    float savunma;































    float saglik;
    float kritik;
}piyade;
struct Okcu {
    float saldiri;
    float savunma;
    float saglik;
    float kritik;
}okcu;
struct Suvari {
    float saldiri;
    float savunma;
    float saglik;
    float kritik;
}suvari;
struct Kusatma_makinesi {
    float saldiri;
    float savunma;
    float saglik;
    float kritik;
}kusatma;

//$$$$$$$$$$$$-ORK_LEGI-$$$$$$$$$$$
struct Dovuscu {
    float saldiri;
    float savunma;
    float saglik;
    float kritik;
}dovuscu;
struct Mizrakci {
    float saldiri;
    float savunma;
    float saglik;
    float kritik;
}mizrakci;
struct Varg_binici {
    float saldiri;
    float savunma;
    float saglik;
    float kritik;
}varg;
struct Troll {
    float saldiri;
    float savunma;
    float saglik;
    float kritik;
}troll;

//----------RESEARCH--------------
struct Level1 {
    int deger;
    char acikla1[100];
};
struct Level2 {
    int deger;
    char acikla2[100];
};
struct Level3 {
    int deger;
    char acikla3[100];
};

struct Savunma_plus {
    struct Level1 level1;
    struct Level2 level2;
    struct Level3 level3;
}savunma_arti;
struct Saldiri_plus {
    struct Level1 level1;
    struct Level2 level2;
    struct Level3 level3;
}saldiri_arti;
struct Egitim_plus {
    struct Level1 level1;
    struct Level2 level2;
    struct Level3 level3;
}egitim_arti;
struct Kusatma_plus {
    struct Level1 level1;
    struct Level2 level2;
    struct Level3 level3;
}kusatma_arti;

//-----------HEROES---------------
//$$$$$$$$$$-INSAN-$$$$$$$$$$$$$$$
struct Alparslan{
    char bonus[20];
    char birim[100];
    int deger;
}alp;
struct Fatih_Sultan_Mehmet{
    char bonus[20];
    char birim[100];
    int deger;
}fatih;
struct Yavuz_Sultan_Selim{
    char bonus[20];
    char birim[100];
    int deger;
}yavuz;
struct Mete_Han{
    char bonus[20];
    char birim[100];
    int deger;
}mete;
struct Turgrul_Bey{
    char bonus[20];
    char birim[100];
    int deger;
}tugrul;

//$$$$$$$$-ORK_LEGI-$$$$$$$$$$
struct Goruk_Vahsi{
    char bonus[20];
    char birim[100];
    int deger;
}goruk;
struct Thruk_Kemikkiran{
    char bonus[20];
    char birim[100];
    int deger;
}thruk;
struct Vrog_Kafakiran{
    char bonus[20];
    char birim[100];
    int deger;
}vrog;
struct Ugar_Zalim{
    char bonus[20];
    char birim[100];
    int deger;
}ugar;

//---------CREATURES--------------
//$$$$$$$$$$-INSAN-$$$$$$$$$$$$$$$
struct Ejderha{
    int deger;
    char tur[10];
    char aciklama[100];
}ejderha;
struct Agri_Devleri {
    int deger;
    char tur[10];
    char aciklama[100];
}agriDev;
struct Tepegoz {
    int deger;
    char tur[10];
    char aciklama[100];
}tepegoz;
struct Karakurt {
    int deger;
    char tur[13];
    char aciklama[100];
}karakurt;
struct Samur {
    int deger;
    char tur[10];
    char aciklama[100];
}samur;

//$$$$$$$$$-ORK_LEGI-$$$$$$$$$$$$
struct Kara_Troll {
    int deger;
    char tur[10];
    char aciklama[100];
}karaTroll;
struct Golge_Kurtlari {
    int deger;
    char tur[10];
    char aciklama[100];
}golgeKurt;
struct Camur_Devleri {
    int deger;
    char tur[10];
    char aciklama[100];
}camurDev;
struct Ates_Ib {
    int deger;
    char tur[10];
    char aciklama[100];
}atesIbl;
struct Buz_Devleri {
    int deger;
    char tur[10];
    char aciklama[100];
}buzDev;
struct Makrog_Savas_Beyi{
    int deger;
    char tur[10];
    char aciklama[100];
}makrog;
//-------------SIDES--------------
struct Insan_Imparatorlugu {
    int piyadeS;
    int okcuS;
    int suvariS;
    int makineS;

    int svnmpls_lvl;
    int sldrpls_lvl;
    int egtmpls_lvl;
    int kstmpls_lvl;

    int alpArslnS;
    int fatihS;
    int yavuzS;
    int meteS;
    int tugrulS;

    int ejderhaS;
    int agriS;
    int tepegozS;
    int karakurtS;
    int samurS;

    float totalGuc;
    float totalSavunma;
    float netH;
}Insan;

struct Ork_legi {
    int dovuscuS;
    int mizrakciS;
    int vargS;
    int trolS;

    int svnmpls_lvl;
    int sldrpls_lvl;
    int egtmpls_lvl;

    int gorukS;
    int thrukS;
    int vrogS;
    int ugarS;

    int krtrllS;
    int golgekrtS;
    int camurdvS;
    int atsiblsS;
    int bzdvS;
    int makrogS;

    float totalGuc;
    float totalSavunma;
    float netH;
}Ork;

//PARAMETERS******************************************************************
void defaultValue(void);
float kritik(float *brlkSaldiriG, float krtkS,int sayac);
void yorgunlukSALDIRI(void);
void yorgunlukSAVUNMA(void);
float saldiri(int birlikS,float birlikG);
float savunma(int brlkS,float savunmaG);
float hasar_dagilimi(float birlikSav,float totalSavunma,float netH);
float net_hasar(float topSaldiriG,float topSavunmaG);
int ReadU(FILE *untPr);
int ReadH(FILE *heroPr);
int ReadC(FILE *creaturesPr);
int ReadR(FILE *researchPr);
int ReadS(FILE *scenarioPr);
void insanBrlk(FILE *dosya);
void ozellikunt(FILE *dosya,char brlk);
void orkBrlk(FILE *dosya);
void insanCnvr(FILE *dosya);
void orkCnvr(FILE *dosya);
void ozellikcnvr(FILE *dosya,char cnvr);
void atamaUNT(FILE *thefile, int num,char brlk,char ozllk[]);
void atamacnvr(FILE *creaturesPr,char cnvr,char sentence[],char whichOne);

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

void drawGrid(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Siyah çizgi rengi

    for (int i = 0; i <= GRID_SIZE; i++) {
        // Dikey çizgiler
        SDL_RenderDrawLine(renderer, i * CELL_SIZE, 0, i * CELL_SIZE, WINDOW_HEIGHT);
        // Yatay çizgiler
        SDL_RenderDrawLine(renderer, 0, i * CELL_SIZE, WINDOW_WIDTH, i * CELL_SIZE);
    }
}

void renderText(SDL_Renderer *renderer, TTF_Font *font, const char *text, int x, int y) {
    SDL_Color color = {4, 161, 4}; // YESIL renk
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect dstrect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void renderTextM(SDL_Renderer *renderer, TTF_Font *font, const char *text, int x, int y) {
    SDL_Color color = {128, 0, 128}; // mor renk
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect dstrect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void renderTextS(SDL_Renderer *renderer, TTF_Font *font, const char *text, int x, int y) {
    SDL_Color color = {255, 255, 0}; // SARI renk
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect dstrect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void renderTextK(SDL_Renderer *renderer, TTF_Font *font, const char *text, int x, int y) {
    SDL_Color color = {200,0, 0, 255}; // KIRMIZI renk
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect dstrect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void renderTextH(SDL_Renderer *renderer, TTF_Font *font, const char *text, int x, int y) {
    SDL_Color color = {0,0, 255, 255}; // mavi renk
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect dstrect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void renderImage(SDL_Renderer *renderer, const char *imagePath, int x, int y) {
    SDL_Texture *texture = IMG_LoadTexture(renderer, imagePath);
    if (texture == NULL) {
        printf("Failed to load texture: %s\n", IMG_GetError());
        return;
    }

    SDL_Rect dstrect = {x, y, CELL_SIZE, CELL_SIZE};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
}

void url()
{
    CURL *curl;
    FILE *fp;
    CURLcode res;

    char *url;
    printf("Kacinci senaryoyu kulanmak istersiniz(1-10 arasi rakam giriniz)?");
    int sayi;
    scanf("%d",&sayi);



    switch(sayi)
    {
    case 1:
        url = "https://yapbenzet.org.tr/1.json";
        break;
    case 2:
        url = "https://yapbenzet.org.tr/2.json";
        break;
    case 3:
        url = "https://yapbenzet.org.tr/3.json";
        break;
    case 4:
        url = "https://yapbenzet.org.tr/4.json";
        break;
    case 5:
        url = "https://yapbenzet.org.tr/5.json";
        break;
    case 6:
        url = "https://yapbenzet.org.tr/6.json";
        break;
    case 7:
        url = "https://yapbenzet.org.tr/7.json";
        break;
    case 8:
        url = "https://yapbenzet.org.tr/8.json";
        break;
    case 9:
        url = "https://yapbenzet.org.tr/9.json";
        break;
    case 10:
        url = "https://yapbenzet.org.tr/10.json";
        break;
    }

    const char *outfilename = "indirilendosya.json";

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename, "wb");
        if (fp == NULL) {
            perror("File opening failed");
            return 1;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        curl_easy_setopt(curl,CURLOPT_SSL_VERIFYPEER,0L);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        fclose(fp);
        curl_easy_cleanup(curl);
    }

    return 0;

}

int main(int argc, char* argv[]) {

    url();
    int grafik = 1;
    FILE *untP = NULL;
    FILE *heroP = NULL;
    FILE *creaturesP = NULL;
    FILE *researchP = NULL;
    FILE *scenarioP = NULL;

    defaultValue();
    ReadU(untP);
    ReadH(heroP);
    ReadC(creaturesP);
    ReadR(researchP);
    ReadS(scenarioP);

    label:
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL Init Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() != 0) {
        printf("TTF Init Error: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        printf("IMG Init Error: %s\n", IMG_GetError());
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("20x20 Izgara", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!window) {
        printf("SDL Create Window Error: %s\n", SDL_GetError());
        IMG_Quit();
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("SDL Create Renderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        IMG_Quit();
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    TTF_Font *font = TTF_OpenFont("C:\\Windows\\Fonts\\ARLRDBD.TTF", 18);
    if (!font) {
        printf("TTF Open Font Error: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        TTF_Quit();
        SDL_Quit();
        return 1;
    }


    SDL_SetRenderDrawColor(renderer, 136, 69, 19, 255); // kahverengi arka plan
    SDL_RenderClear(renderer);

    drawGrid(renderer);


    //PIYADE GRAFÝK
    if(Insan.piyadeS!=0){
    int satirP = Insan.piyadeS/100;
    for(int p=0;satirP>p;p++){
        char str[3]; // Yeterli boyutta bir karakter dizisi oluþturun
        sprintf(str, "%d", p);
        renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\piyade.jpg", 0 * CELL_SIZE, p * CELL_SIZE);
        renderText(renderer, font, "100", 0 * CELL_SIZE + (CELL_SIZE / 3), p * CELL_SIZE + (CELL_SIZE / 1.5));
    }
    if(Insan.piyadeS-(satirP*100) != 0){
    char sonP[3];
    sprintf(sonP, "%d", Insan.piyadeS-(satirP*100));
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\piyade.jpg", 0 * CELL_SIZE, satirP * CELL_SIZE);
    if(Insan.piyadeS-(satirP*100)<50 ){
     if(grafik==1)
      renderText(renderer, font, sonP, 0 * CELL_SIZE + (CELL_SIZE / 3), satirP * CELL_SIZE + (CELL_SIZE / 1.5));
     else
      renderTextK(renderer, font, sonP, 0 * CELL_SIZE + (CELL_SIZE / 3), satirP * CELL_SIZE + (CELL_SIZE / 1.5));}
    if(Insan.piyadeS-(satirP*100)>=50){
     if(grafik==1)
      renderText(renderer, font, sonP, 0 * CELL_SIZE + (CELL_SIZE / 3), satirP * CELL_SIZE + (CELL_SIZE / 1.5));
     else
      renderTextK(renderer, font, sonP, 0 * CELL_SIZE + (CELL_SIZE / 3), satirP * CELL_SIZE + (CELL_SIZE / 1.5));}}}


    //OKCU GRAFÝK
    if(Insan.okcuS!=0){
    int satirO = Insan.okcuS/100;
    for(int p=0;satirO>p;p++){
        char str[3]; // Yeterli boyutta bir karakter dizisi oluþturun
        sprintf(str, "%d", p);
        renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\okcu.jpg", 1 * CELL_SIZE, p * CELL_SIZE);
        renderText(renderer, font, "100", 1 * CELL_SIZE + (CELL_SIZE / 3), p * CELL_SIZE + (CELL_SIZE / 1.5));
    }
    if(Insan.okcuS-(satirO*100) != 0){
    char sonO[3];
    sprintf(sonO, "%d", Insan.okcuS-(satirO*100));
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\okcu.jpg", 1 * CELL_SIZE, satirO * CELL_SIZE);
    if(Insan.okcuS-(satirO*100)<50 ){
     if(grafik==1)
      renderText(renderer, font, sonO, 1 * CELL_SIZE + (CELL_SIZE / 3), satirO * CELL_SIZE + (CELL_SIZE / 1.5));
     else
      renderTextK(renderer, font, sonO, 1 * CELL_SIZE + (CELL_SIZE / 3), satirO * CELL_SIZE + (CELL_SIZE / 1.5));}
    if(Insan.okcuS-(satirO*100)>=50){
     if(grafik==1)
      renderText(renderer, font, sonO, 1 * CELL_SIZE + (CELL_SIZE / 3), satirO * CELL_SIZE + (CELL_SIZE / 1.5));
     else
      renderTextS(renderer, font, sonO, 1 * CELL_SIZE + (CELL_SIZE / 3), satirO * CELL_SIZE + (CELL_SIZE / 1.5));}}}


    //SUVARI GRAFÝK
    if(Insan.suvariS!=0){
    int satirs = Insan.suvariS/100;
    for(int p=0;satirs>p;p++){
        char str[3]; // Yeterli boyutta bir karakter dizisi oluþturun
        sprintf(str, "%d", p);
        renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\suvari.jpg", 2 * CELL_SIZE, p * CELL_SIZE);
        renderText(renderer, font, "100", 2 * CELL_SIZE + (CELL_SIZE / 3), p * CELL_SIZE + (CELL_SIZE / 1.5));
    }
    if(Insan.suvariS-(satirs*100) != 0){
    char sonS[3];
    sprintf(sonS, "%d", Insan.suvariS-(satirs*100));
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\suvari.jpg", 2 * CELL_SIZE, satirs * CELL_SIZE);
    if(Insan.suvariS-(satirs*100)<50 ){
     if(grafik==1)
      renderText(renderer, font, sonS, 2 * CELL_SIZE + (CELL_SIZE / 3), satirs * CELL_SIZE + (CELL_SIZE / 1.5));
     else
      renderTextK(renderer, font, sonS, 2 * CELL_SIZE + (CELL_SIZE / 3), satirs * CELL_SIZE + (CELL_SIZE / 1.5));}
    if(Insan.suvariS-(satirs*100)>=50){
     if(grafik==1)
      renderText(renderer, font, sonS, 2 * CELL_SIZE + (CELL_SIZE / 3), satirs * CELL_SIZE + (CELL_SIZE / 1.5));
     else
      renderTextS(renderer, font, sonS, 2 * CELL_SIZE + (CELL_SIZE / 3), satirs * CELL_SIZE + (CELL_SIZE / 1.5));}}}


    //KUSATMA GRAFÝK
    if(Insan.makineS!=0){
    int satirK = Insan.makineS/100;
    for(int p=0;satirK>p;p++){
        char str[3]; // Yeterli boyutta bir karakter dizisi oluþturun
        sprintf(str, "%d", p);
        renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\kusatma.jpg", 3 * CELL_SIZE, p * CELL_SIZE);
        renderText(renderer, font, "100", 3 * CELL_SIZE + (CELL_SIZE / 3), p * CELL_SIZE + (CELL_SIZE / 1.5));
    }
    if(Insan.makineS-(satirK*100) != 0){
    char sonK[3];
    sprintf(sonK, "%d", Insan.makineS-(satirK*100));
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\kusatma.jpg", 3 * CELL_SIZE, satirK * CELL_SIZE);
    if(Insan.makineS-(satirK*100)<50 ){
     if(grafik==1)
      renderText(renderer, font, sonK, 3 * CELL_SIZE + (CELL_SIZE / 3), satirK * CELL_SIZE + (CELL_SIZE / 1.5));
     else
      renderTextK(renderer, font, sonK, 3 * CELL_SIZE + (CELL_SIZE / 3), satirK * CELL_SIZE + (CELL_SIZE / 1.5));}
    if(Insan.makineS-(satirK*100)>=50){
     if(grafik==1)
      renderText(renderer, font, sonK, 3 * CELL_SIZE + (CELL_SIZE / 3), satirK * CELL_SIZE + (CELL_SIZE / 1.5));
     else
      renderTextS(renderer, font, sonK, 3 * CELL_SIZE + (CELL_SIZE / 3), satirK * CELL_SIZE + (CELL_SIZE / 1.5));}}}


    //----------------------------------------------------------------------------------------------------------------

    //DOVUSCU GRAFÝK
    if(Ork.dovuscuS!=0){
    int satirD = Ork.dovuscuS/100;
    for(int p=0;satirD>p;p++){
        char str[3]; // Yeterli boyutta bir karakter dizisi oluþturun
        sprintf(str, "%d", p);
        renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\orkdovuscusu.jpg", 9 * CELL_SIZE, p * CELL_SIZE);
        renderText(renderer, font, "100", 9 * CELL_SIZE + (CELL_SIZE / 3), p * CELL_SIZE + (CELL_SIZE / 1.5));
    }
    if(Ork.dovuscuS-(satirD*100) != 0){
    char sonD[3];
    sprintf(sonD, "%d", Ork.dovuscuS-(satirD*100));
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\orkdovuscusu.jpg", 9 * CELL_SIZE, satirD * CELL_SIZE);
    if(Ork.dovuscuS-(satirD*100)<50 ){
     if(grafik==1)
      renderText(renderer, font, sonD, 9 * CELL_SIZE + (CELL_SIZE / 3), satirD * CELL_SIZE + (CELL_SIZE / 1.5));
     else
      renderTextK(renderer, font, sonD, 9 * CELL_SIZE + (CELL_SIZE / 3), satirD * CELL_SIZE + (CELL_SIZE / 1.5));}
    if(Ork.dovuscuS-(satirD*100)>=50){
     if(grafik==1)
      renderText(renderer, font, sonD, 9 * CELL_SIZE + (CELL_SIZE / 3), satirD * CELL_SIZE + (CELL_SIZE / 1.5));
     else
      renderTextS(renderer, font, sonD, 9 * CELL_SIZE + (CELL_SIZE / 3), satirD * CELL_SIZE + (CELL_SIZE / 1.5));}}}


    //MIZRAKCI GRAFÝK
    if(Ork.mizrakciS!=0){
    int satirM = Ork.mizrakciS/100;
    for(int p=0;satirM>p;p++){
        char str[3]; // Yeterli boyutta bir karakter dizisi oluþturun
        sprintf(str, "%d", p);
        renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\mizrakci.jpg", 8 * CELL_SIZE, p * CELL_SIZE);
        renderText(renderer, font, "100", 8 * CELL_SIZE + (CELL_SIZE / 3), p * CELL_SIZE + (CELL_SIZE / 1.5));
    }
    if(Ork.mizrakciS-(satirM*100) != 0){
    char sonM[3];
    sprintf(sonM, "%d", Ork.mizrakciS-(satirM*100));
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\mizrakci.jpg", 8 * CELL_SIZE, satirM * CELL_SIZE);
    if(Ork.mizrakciS-(satirM*100)<50 ){
     if(grafik==1)
      renderText(renderer, font, sonM, 8 * CELL_SIZE + (CELL_SIZE / 3), satirM * CELL_SIZE + (CELL_SIZE / 1.5));
     else
      renderTextK(renderer, font, sonM, 8 * CELL_SIZE + (CELL_SIZE / 3), satirM * CELL_SIZE + (CELL_SIZE / 1.5));}
    if(Ork.mizrakciS-(satirM*100)>=50){
     if(grafik==1)
      renderText(renderer, font, sonM, 8 * CELL_SIZE + (CELL_SIZE / 3), satirM * CELL_SIZE + (CELL_SIZE / 1.5));
     else
      renderTextS(renderer, font, sonM, 8 * CELL_SIZE + (CELL_SIZE / 3), satirM * CELL_SIZE + (CELL_SIZE / 1.5));}}}


    //varg GRAFÝK
    if(Ork.vargS!=0){
    int satirV = Ork.vargS/100;
    for(int p=0;satirV>p;p++){
        char str[3]; // Yeterli boyutta bir karakter dizisi oluþturun
        sprintf(str, "%d", p);
        renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\varg.jpg", 7 * CELL_SIZE, p * CELL_SIZE);
        renderText(renderer, font, "100", 7 * CELL_SIZE + (CELL_SIZE / 3), p * CELL_SIZE + (CELL_SIZE / 1.5));
    }
    if(Ork.vargS-(satirV*100) != 0){
    char sonV[3];
    sprintf(sonV, "%d", Ork.vargS-(satirV*100));
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\varg.jpg", 7 * CELL_SIZE, satirV * CELL_SIZE);
    if(Ork.vargS-(satirV*100)<50 ){
     if(grafik==1)
      renderText(renderer, font, sonV, 7 * CELL_SIZE + (CELL_SIZE / 3), satirV * CELL_SIZE + (CELL_SIZE / 1.5));
     else
      renderTextK(renderer, font, sonV, 7 * CELL_SIZE + (CELL_SIZE / 3), satirV * CELL_SIZE + (CELL_SIZE / 1.5));}
    if(Ork.vargS-(satirV*100)>=50){
     if(grafik==1)
      renderText(renderer, font, sonV, 7 * CELL_SIZE + (CELL_SIZE / 3), satirV * CELL_SIZE + (CELL_SIZE / 1.5));
     else
      renderTextS(renderer, font, sonV, 7 * CELL_SIZE + (CELL_SIZE / 3), satirV * CELL_SIZE + (CELL_SIZE / 1.5));}}}

    //TROLL GRAFÝK
    if(Ork.trolS!=0){
    int satirT = Ork.trolS/100;
    for(int p=0;satirT>p;p++){
        char str[3]; // Yeterli boyutta bir karakter dizisi oluþturun
        sprintf(str, "%d", p);
        renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\troll.jpeg.jpg", 6 * CELL_SIZE, p * CELL_SIZE);
        renderText(renderer, font, "100", 6 * CELL_SIZE + (CELL_SIZE / 3), p * CELL_SIZE + (CELL_SIZE / 1.5));
    }
    if(Ork.trolS-(satirT*100) != 0){
    char sonT[3];
    sprintf(sonT, "%d", Ork.trolS-(satirT*100));
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\troll.jpeg.jpg", 6 * CELL_SIZE, satirT * CELL_SIZE);
    if(Ork.trolS-(satirT*100)<50 ){
     if(grafik==1)
      renderText(renderer, font, sonT, 6 * CELL_SIZE + (CELL_SIZE / 3), satirT * CELL_SIZE + (CELL_SIZE / 1.5));
     else
      renderTextK(renderer, font, sonT, 6 * CELL_SIZE + (CELL_SIZE / 3), satirT * CELL_SIZE + (CELL_SIZE / 1.5));}
    if(Ork.trolS-(satirT*100)>=50){
     if(grafik==1)
      renderText(renderer, font, sonT, 6 * CELL_SIZE + (CELL_SIZE / 3), satirT * CELL_SIZE + (CELL_SIZE / 1.5));
     else
      renderTextS(renderer, font, sonT, 6 * CELL_SIZE + (CELL_SIZE / 3), satirT * CELL_SIZE + (CELL_SIZE / 1.5));}}}


    //---------------------------------------------------------------------------------------------------------


    //EJDERHA GRAFÝK
    if(Insan.ejderhaS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\ejderha.jpg", 4 * CELL_SIZE, 0 * CELL_SIZE);
    renderTextM(renderer, font, "ejder", 4 * CELL_SIZE + (CELL_SIZE / 3), 0 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //AGRI GRAFÝK
    if(Insan.ejderhaS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\agri.jpg", 4 * CELL_SIZE, 1 * CELL_SIZE);
    renderTextM(renderer, font, "agri", 4 * CELL_SIZE + (CELL_SIZE / 3), 1 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //tepe GRAFÝK
    if(Insan.tepegozS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\tepegoz.jpg", 4 * CELL_SIZE, 2 * CELL_SIZE);
    renderTextM(renderer, font, "tepe", 4 * CELL_SIZE + (CELL_SIZE / 3), 2 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //kurt GRAFÝK
    if(Insan.karakurtS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\karakurt.jpg", 4 * CELL_SIZE, 3 * CELL_SIZE);
    renderTextM(renderer, font, "kurt", 4 * CELL_SIZE + (CELL_SIZE / 3), 3 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //samur GRAFÝK
    if(Insan.samurS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\samur.jpg", 4 * CELL_SIZE, 4 * CELL_SIZE);
    renderTextM(renderer, font, "samur", 4 * CELL_SIZE + (CELL_SIZE / 3), 4 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //-------------------------------------------------------------------------------------------------------------------

    //karatrol GRAFÝK
    if(Ork.krtrllS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\kara troll.jpg", 5 * CELL_SIZE, 0 * CELL_SIZE);
    renderTextM(renderer, font, "troll", 5 * CELL_SIZE + (CELL_SIZE / 3), 0 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //gölge GRAFÝK
    if(Ork.golgekrtS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\golge.jpeg.jpg", 5 * CELL_SIZE, 1 * CELL_SIZE);
    renderTextM(renderer, font, "golge", 5 * CELL_SIZE + (CELL_SIZE / 3), 1 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //camur GRAFÝK
    if(Ork.camurdvS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\camur.jpg", 5 * CELL_SIZE, 2 * CELL_SIZE);
    renderTextM(renderer, font, "camur", 5 * CELL_SIZE + (CELL_SIZE / 3), 2 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //ates GRAFÝK
    if(Ork.atsiblsS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\ates.jpg", 5 * CELL_SIZE, 3 * CELL_SIZE);
    renderTextM(renderer, font, "ates", 5 * CELL_SIZE + (CELL_SIZE / 3), 3 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //makrog GRAFÝK
    if(Ork.makrogS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\makrog.jpg", 5 * CELL_SIZE, 4 * CELL_SIZE);
    renderTextM(renderer, font, "makrog", 5 * CELL_SIZE + (CELL_SIZE / 3), 4 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //buz GRAFÝK
    if(Ork.bzdvS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\buz.jpg", 5 * CELL_SIZE, 5 * CELL_SIZE);
    renderTextM(renderer, font, "buz", 5 * CELL_SIZE + (CELL_SIZE / 3), 5 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //---------------------------------------------------------------------------------------------------------------


    //ALP GRAFÝK
    if(Insan.alpArslnS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\alpArslan.jpeg.jpg", 4 * CELL_SIZE, 5 * CELL_SIZE);
    renderTextH(renderer, font, "alp", 4 * CELL_SIZE + (CELL_SIZE / 3), 5 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //FATIH GRAFÝK
    if(Insan.fatihS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\fatih.jpg", 4 * CELL_SIZE, 6 * CELL_SIZE);
    renderTextH(renderer, font, "fatih", 4 * CELL_SIZE + (CELL_SIZE / 3), 6 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //mete GRAFÝK
    if(Insan.meteS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\mete.jpg", 4 * CELL_SIZE, 7 * CELL_SIZE);
    renderTextH(renderer, font, "mete", 4 * CELL_SIZE + (CELL_SIZE / 3), 7 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //yavuz GRAFÝK
    if(Insan.yavuzS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\yavuz.jpg", 4 * CELL_SIZE, 8* CELL_SIZE);
    renderTextH(renderer, font, "yavuz", 4 * CELL_SIZE + (CELL_SIZE / 3), 8 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //tugrul GRAFÝK
    if(Insan.tugrulS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\tugrul.jpg", 4 * CELL_SIZE, 9 * CELL_SIZE);
    renderTextH(renderer, font, "tugrul", 4 * CELL_SIZE + (CELL_SIZE / 3), 9 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //-------------------------------------------------------------------------------------------------------------------

    //goruk GRAFÝK
    if(Ork.gorukS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\goruk.jpg", 5 * CELL_SIZE, 6 * CELL_SIZE);
    renderTextH(renderer, font, "goruk", 5 * CELL_SIZE + (CELL_SIZE / 3), 6 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //tHruk GRAFÝK
    if(Ork.thrukS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\thruk.jpg", 5 * CELL_SIZE, 7 * CELL_SIZE);
    renderTextH(renderer, font, "thruk", 5 * CELL_SIZE + (CELL_SIZE / 3), 7 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //vrog GRAFÝK
    if(Ork.vrogS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\vrog.jpg", 5 * CELL_SIZE, 8 * CELL_SIZE);
    renderTextH(renderer, font, "vrog", 5 * CELL_SIZE + (CELL_SIZE / 3), 8 * CELL_SIZE + (CELL_SIZE / 1.5));
    }

    //ugar GRAFÝK
    if(Ork.ugarS!=0){
    renderImage(renderer, "C:\\Users\\alpsl\\Desktop\\230202039_230202010\\ugar.jpg", 5 * CELL_SIZE, 9 * CELL_SIZE);
    renderTextH(renderer, font, "ugar", 5 * CELL_SIZE + (CELL_SIZE / 3), 9 * CELL_SIZE + (CELL_SIZE / 1.5));
    }






    SDL_RenderPresent(renderer);

    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);





    //--------------------------------------mekanik--------------------------------------------------
    if(grafik <2){
    int sayacPIYADE = 0;
    int sayacOKCU = 0;
    int sayacSUVARI = 0;
    int sayacKUSATMA = 0;
    int sayacDOVUSCU = 0;
    int sayacMIZRAKCI = 0;
    int sayacVARG = 0;
    int sayacTROLL = 0;
    int sayacGENEL=0;
    float test = 0;
    float hasar =0;
    float extraHasar =0;


    FILE *writing = fopen("savas_sim.txt", "w");
    if (writing == NULL) {
        printf("Dosya savas_sim.txt acilamadi\n");
        return 0;
    }


    printf("\n%d",Insan.piyadeS);
    printf("\n%d",Insan.okcuS);
    printf("\n%d",Insan.suvariS);
    printf("\n%d",Insan.makineS);
    printf("\n%d",Ork.dovuscuS);
    printf("\n%d",Ork.vargS);
    printf("\n%d",Ork.mizrakciS);
    printf("\n%d",Ork.trolS);

    if (Insan.alpArslnS) {
        if (strstr(&alp.birim[0], "p")) {
            if (strstr(&alp.bonus[2], "v")) {
                piyade.savunma = piyade.savunma * (100 + alp.deger) / 100;
            }
        }
    }else if (Insan.meteS) {
        if (strstr(&mete.birim[0], "o")) {
            if (strstr(&mete.bonus[2], "v")) {
                okcu.savunma = okcu.savunma * (100 + mete.deger) / 100;
            }
        }
    }else if (Insan.tugrulS) {
        if (strstr(&tugrul.birim[0], "o")) {
            if (strstr(&tugrul.bonus[2], "v")) {
                okcu.savunma = okcu.savunma * (100 + tugrul.deger) / 100;
            }
        }
    }
    else if (Insan.yavuzS) {
        if (strstr(&yavuz.birim[0], "s")) {
            if (strstr(&yavuz.bonus[2], "i")) {
                suvari.kritik = suvari.kritik * (100 + yavuz.deger) / 100;
            }
        }
    }else if (Insan.fatihS) {
        if (strstr(&fatih.birim[0], "k")) {
            if (strstr(&fatih.bonus[2], "l")) {
                kusatma.saldiri = kusatma.saldiri * (100 + fatih.deger) / 100;
            }
        }
    }
    if (Ork.gorukS) {
        if (strstr(&goruk.birim[0], "o")) {
            if (strstr(&goruk.bonus[2], "l")) {
                dovuscu.saldiri = dovuscu.saldiri * (100 + goruk.deger) / 100;
            }
        }
    }else if (Ork.ugarS) {
        if (strstr(&ugar.bonus[2], "v")) {
            dovuscu.savunma = dovuscu.savunma * (100 + ugar.deger) / 100;
            mizrakci.savunma = mizrakci.savunma * (100 + ugar.deger) / 100;
            varg.savunma = varg.savunma * (100 + ugar.deger) / 100;
            troll.savunma = troll.savunma * (100 + ugar.deger) / 100;
        }
    }else if (Ork.vrogS) {
        if (strstr(&vrog.birim[0], "v")) {
            if (strstr(&vrog.bonus[2], "k")) {
                varg.kritik = varg.kritik * (100 + vrog.deger) / 100;
            }
        }
    }else if (Ork.thrukS) {
        if (strstr(&thruk.birim[0], "t")) {
            if (strstr(&thruk.bonus[2], "v")) {
                troll.savunma = troll.savunma * (100 + thruk.deger) / 100;

            }
        }
    }

    if(Insan.ejderhaS){
        if (strstr(&ejderha.aciklama[0], "p")) {
            if (strstr(&ejderha.tur[2], "l")) {
                piyade.saldiri = piyade.saldiri * (100 + ejderha.deger) / 100;
            }
        }
    }
    else if(Insan.agriS){
        if (strstr(&agriDev.aciklama[0], "s")) {
            if (strstr(&agriDev.tur[2], "v")) {
                suvari.savunma = suvari.savunma * (100 + agriDev.deger) / 100;
            }
        }
    }
    else if(Insan.tepegozS){
        if (strstr(&tepegoz.aciklama[0], "o")) {
            if (strstr(&tepegoz.tur[2], "l")) {
                okcu.saldiri = okcu.saldiri * (100 + tepegoz.deger) / 100;
            }
        }
    }
    else if(Insan.karakurtS){
        if (strstr(&karakurt.aciklama[0], "o")) {
            if (strstr(&karakurt.tur[2], "t")) {
                okcu.kritik = okcu.kritik * (100 + karakurt.deger) / 100;
            }
        }
    }
    else if(Insan.samurS){
        if (strstr(&samur.aciklama[0], "o")) {
            if (strstr(&samur.tur[2], "t")) {
                piyade.savunma = piyade.savunma * (100 + samur.deger) / 100;
            }
        }
    }else
        printf("girmedi");

    if(Ork.krtrllS){
        if (strstr(&karaTroll.aciklama[0], "t")) {
            if (strstr(&karaTroll.tur[2], "l")) {
                troll.saldiri = troll.saldiri * (100 + karaTroll.deger) / 100;
            }
        }
    }
    else if(Ork.golgekrtS){
        if (strstr(&golgeKurt.aciklama[0], "v")) {
            if (strstr(&golgeKurt.tur[2], "v")) {
                varg.savunma = varg.savunma * (100 + golgeKurt.deger) / 100;
            }
        }
    }
    else if(Ork.camurdvS){
        if (strstr(&camurDev.aciklama[0], "d")) {
            if (strstr(&camurDev.tur[2], "v")) {
                dovuscu.savunma = dovuscu.savunma * (100 + camurDev.deger) / 100;
            }
        }
    }
    else if(Ork.atsiblsS){
        if (strstr(&atesIbl.aciklama[0], "v")) {
            if (strstr(&atesIbl.tur[2], "l")) {
                varg.saldiri = varg.saldiri * (100 + atesIbl.deger) / 100;
            }
        }
    }
    else if(Ork.makrogS){
        if (strstr(&makrog.aciklama[0], "t")) {
            if (strstr(&makrog.tur[2], "v")) {
                troll.savunma = troll.savunma * (100 + makrog.deger) / 100;
            }
        }
    }
    else if(Ork.bzdvS){
        if (strstr(&buzDev.aciklama[0], "m")) {
            if (strstr(&buzDev.tur[2], "v")) {
                mizrakci.savunma = mizrakci.savunma * (100 + buzDev.deger) / 100;
            }
        }
    }

    if (Insan.svnmpls_lvl) {
        fprintf(writing, "Insan Arastirma seviyesi : Savunma seviyesi %d; ",Insan.svnmpls_lvl);
        switch (Insan.svnmpls_lvl) {
            case 1:
                piyade.savunma = piyade.savunma * 1.1;
                okcu.savunma = okcu.savunma * 1.1;
                suvari.savunma = suvari.savunma * 1.1;
                kusatma.savunma = kusatma.savunma * 1.1;
                fprintf(writing, "%s\n",savunma_arti.level1.acikla1);
                break;
            case 2:
                piyade.savunma = piyade.savunma * 1.2;
                okcu.savunma = okcu.savunma * 1.2;
                suvari.savunma = suvari.savunma * 1.2;
                kusatma.savunma = kusatma.savunma * 1.2;
                fprintf(writing, "%s\n",savunma_arti.level2.acikla2);
                break;
            case 3:
                piyade.savunma = piyade.savunma * 1.3;
                okcu.savunma = okcu.savunma * 1.3;
                suvari.savunma = suvari.savunma * 1.3;
                kusatma.savunma = kusatma.savunma * 1.3;
                fprintf(writing, "%s\n",savunma_arti.level3.acikla3);
                break;
            default:
                break;
        }
    }else if (Insan.sldrpls_lvl) {
        fprintf(writing, "Insan Arastirma seviyesi : Saldiri seviyesi %d; ",Insan.sldrpls_lvl);
        switch (Insan.sldrpls_lvl) {
            case 1:
                piyade.saldiri = piyade.saldiri * 1.1;
                okcu.saldiri = okcu.saldiri * 1.1;
                suvari.saldiri = suvari.saldiri * 1.1;
                kusatma.saldiri = kusatma.saldiri * 1.1;
                fprintf(writing, "%s\n",saldiri_arti.level1.acikla1);
                break;
            case 2:
                piyade.saldiri = piyade.saldiri * 1.2;
                okcu.saldiri = okcu.saldiri * 1.2;
                suvari.saldiri = suvari.saldiri * 1.2;
                kusatma.saldiri = kusatma.saldiri * 1.2;
                fprintf(writing, "%s\n",saldiri_arti.level2.acikla2);
                break;
            case 3:
                piyade.saldiri = piyade.saldiri * 1.3;
                okcu.saldiri = okcu.saldiri * 1.3;
                suvari.saldiri = suvari.saldiri * 1.3;
                kusatma.saldiri = kusatma.saldiri * 1.3;
                fprintf(writing, "%s\n",saldiri_arti.level3.acikla3);
                break;
            default:
                break;
        }
    }else if (Insan.kstmpls_lvl) {
        fprintf(writing, "Insan Arastirma seviyesi : Kusatma seviyesi %d; ",Insan.kstmpls_lvl);
        switch (Insan.kstmpls_lvl) {
            case 1:
                kusatma.saldiri = kusatma.saldiri * 1.1;
                fprintf(writing, "%s\n",kusatma_arti.level1.acikla1);
                break;
            case 2:
                kusatma.saldiri = kusatma.saldiri * 1.2;
                fprintf(writing, "%s\n",kusatma_arti.level2.acikla2);
                break;
            case 3:
                kusatma.saldiri = kusatma.saldiri * 1.3;
                fprintf(writing, "%s\n",kusatma_arti.level3.acikla3);
                break;
            default:
                break;
        }
    }else if (Insan.egtmpls_lvl){
        fprintf(writing, "Insan Arastirma seviyesi : Egitim seviyesi %d; ",Insan.egtmpls_lvl);
        switch (Insan.egtmpls_lvl) {
            case 1:
                piyade.kritik = piyade.kritik * 1.05;
                okcu.kritik = okcu.kritik * 1.05;
                suvari.kritik = suvari.kritik * 1.05;
                kusatma.kritik = kusatma.kritik * 1.05;
                fprintf(writing, "%s\n",egitim_arti.level1.acikla1);
                break;
            case 2:
                piyade.kritik = piyade.kritik * 1.1;
                okcu.kritik = okcu.kritik * 1.1;
                suvari.kritik = suvari.kritik * 1.1;
                kusatma.kritik = kusatma.kritik * 1.1;
                fprintf(writing, "%s\n",egitim_arti.level2.acikla2);
                break;
            case 3:
                piyade.kritik = piyade.kritik * 1.15;
                okcu.kritik = okcu.kritik * 1.15;
                suvari.kritik = suvari.kritik * 1.15;
                kusatma.kritik = kusatma.kritik * 1.15;
                fprintf(writing, "%s\n",egitim_arti.level3.acikla3);
                break;
            default:
                break;
        }
    }
    if (Ork.svnmpls_lvl) {
        fprintf(writing, "Ork Arastirma seviyesi : Savunma seviyesi %d; ",Ork.svnmpls_lvl);
        switch (Ork.svnmpls_lvl) {
            case 1:
                dovuscu.savunma = dovuscu.savunma * 1.1;
                varg.savunma = varg.savunma * 1.1;
                mizrakci.savunma = mizrakci.savunma * 1.1;
                varg.savunma = varg.savunma * 1.1;
                fprintf(writing, "%s\n",savunma_arti.level1.acikla1);
                break;
            case 2:
                dovuscu.savunma = dovuscu.savunma * 1.2;
                varg.savunma = varg.savunma * 1.2;
                mizrakci.savunma = mizrakci.savunma * 1.2;
                varg.savunma = varg.savunma * 1.2;
                fprintf(writing, "%s\n",savunma_arti.level2.acikla2);
                break;
            case 3:
                dovuscu.savunma = dovuscu.savunma * 1.3;
                varg.savunma = varg.savunma * 1.3;
                mizrakci.savunma = mizrakci.savunma * 1.3;
                varg.savunma = varg.savunma * 1.3;
                fprintf(writing, "%s\n",savunma_arti.level3.acikla3);
                break;
            default:
                break;
        }
    }else if (Ork.sldrpls_lvl) {
        fprintf(writing, "Ork Arastirma seviyesi : Saldiri seviyesi %d; ",Ork.sldrpls_lvl);
        switch (Ork.sldrpls_lvl) {
            case 1:
                dovuscu.saldiri = dovuscu.saldiri * 1.1;
                varg.saldiri = varg.saldiri * 1.1;
                mizrakci.saldiri = mizrakci.saldiri * 1.1;
                varg.saldiri = varg.saldiri * 1.1;
                fprintf(writing, "%s\n",saldiri_arti.level1.acikla1);
                break;
            case 2:
                dovuscu.saldiri = dovuscu.saldiri * 1.2;
                varg.saldiri = varg.saldiri * 1.2;
                mizrakci.saldiri = mizrakci.saldiri * 1.2;
                varg.saldiri = varg.saldiri * 1.2;
                fprintf(writing, "%s\n",saldiri_arti.level2.acikla2);
                break;
            case 3:
                dovuscu.saldiri = dovuscu.saldiri * 1.3;
                varg.saldiri = varg.saldiri * 1.3;
                mizrakci.saldiri = mizrakci.saldiri * 1.3;
                varg.saldiri = varg.saldiri * 1.3;
                fprintf(writing, "%s\n",saldiri_arti.level3.acikla3);
                break;
            default:
                break;
        }
    }else if (Ork.egtmpls_lvl) {
        fprintf(writing, "Insan Arastirma seviyesi : Egitim seviyesi %d; ",Insan.egtmpls_lvl);
        switch (Ork.egtmpls_lvl) {
            case 1:
                dovuscu.kritik = dovuscu.kritik * 1.05;
                mizrakci.kritik = mizrakci.kritik * 1.05;
                varg.kritik = varg.kritik * 1.05;
                troll.kritik = troll.kritik * 1.05;
                fprintf(writing, "%s\n",egitim_arti.level1.acikla1);
                break;
            case 2:
                dovuscu.kritik = dovuscu.kritik * 1.1;
                mizrakci.kritik = mizrakci.kritik * 1.1;
                varg.kritik = varg.kritik * 1.1;
                troll.kritik = troll.kritik * 1.1;
                fprintf(writing, "%s\n",egitim_arti.level2.acikla2);
                break;
            case 3:
                dovuscu.kritik = dovuscu.kritik * 1.15;
                mizrakci.kritik = mizrakci.kritik * 1.15;
                varg.kritik = varg.kritik * 1.15;
                troll.kritik = troll.kritik * 1.15;
                fprintf(writing, "%s\n",egitim_arti.level3.acikla3);
                break;
            default:
                break;
        }
    }
    fprintf(writing, "Insan imparatorlugu :\n");
    fprintf(writing, "Piyadeler : %d birim (Saldiri %.f,Savunma %.f, Saglik %.f, Kritik %.f)\n",Insan.piyadeS,piyade.saldiri,piyade.savunma,piyade.saglik,piyade.kritik);
    fprintf(writing, "Suvariler : %d birim (Saldiri %.f,Savunma %.f, Saglik %.f, Kritik %.f)\n",Insan.suvariS,suvari.saldiri,suvari.savunma,suvari.saglik,suvari.kritik);
    fprintf(writing, "Okcular : %d birim (Saldiri %.f,Savunma %.f, Saglik %.f, Kritik %.f)\n",Insan.okcuS,okcu.saldiri,okcu.savunma,okcu.saglik,okcu.kritik);
    fprintf(writing, "Kusatma makineleri : %d birim (Saldiri %.f,Savunma %.f, Saglik %.f, Kritik %.f)\n",Insan.makineS,kusatma.saldiri,kusatma.savunma,kusatma.saglik,kusatma.kritik);
    if (Insan.alpArslnS) {
        fprintf(writing, "Alparslan : %s\n",alp.birim);
    }else if (Insan.meteS) {
        fprintf(writing, "Mete Han : %s\n",mete.birim);
    }else if (Insan.yavuzS) {
        fprintf(writing, "Yavus Sultan Selim : %s\n",yavuz.birim);
    }else if (Insan.fatihS) {
        fprintf(writing, "Fatih Sultan Mehmet : %s\n",fatih.birim);
    }else if (Insan.tugrulS) {
        fprintf(writing, "Tugrul Han : %s\n",tugrul.birim);
    }
    if (Insan.tepegozS) {
        fprintf(writing, "Tepegoz : %s\n",tepegoz.aciklama);
    }else if (Insan.karakurtS) {
        fprintf(writing, "Karakurt : %s\n",karakurt.aciklama);
    }else if (Insan.ejderhaS) {
        fprintf(writing, "Ejderha : %s\n",ejderha.aciklama);
    }else if (Insan.agriS) {
        fprintf(writing, "Agri dagi devi : %s\n",agriDev.aciklama);
    }else if (Insan.samurS) {
        fprintf(writing, "Samur : %s\n",samur.aciklama);
    }
    fprintf(writing, "\nOrk Legi :\n");
    fprintf(writing, "Ork dovusculeri : %d birim (Saldiri %.f,Savunma %.f, Saglik %.f, Kritik %.f)\n",Ork.dovuscuS,dovuscu.saldiri,dovuscu.savunma,dovuscu.saglik,dovuscu.kritik);
    fprintf(writing, "Mizrakcila : %d birim (Saldiri %.f,Savunma %.f, Saglik %.f, Kritik %.f)\n",Ork.mizrakciS,mizrakci.saldiri,mizrakci.savunma,mizrakci.saglik,mizrakci.kritik);
    fprintf(writing, "Varg binicileri : %d birim (Saldiri %.f,Savunma %.f, Saglik %.f, Kritik %.f)\n",Ork.vargS,varg.saldiri,varg.savunma,varg.saglik,varg.kritik);
    fprintf(writing, "Troller : %d birim (Saldiri %.f,Savunma %.f, Saglik %.f, Kritik %.f)\n",Ork.trolS,troll.saldiri,troll.savunma,troll.saglik,troll.kritik);
    if (Ork.vrogS) {
        fprintf(writing, "Vrog Kafakiran : %s\n",vrog.birim);
    }else if (Ork.thrukS) {
        fprintf(writing, "Thruk Kemikkiran : %s\n",thruk.birim);
    }else if (Ork.gorukS) {
        fprintf(writing, "Goruk Vahsi : %s\n",goruk.birim);
    }else if (Ork.ugarS) {
        fprintf(writing, "Ugar Zalim : %s\n",ugar.birim);
    }
    if (Ork.krtrllS) {
        fprintf(writing, "Kara Troll : %s\n",karaTroll.aciklama);
    }else if (Ork.camurdvS) {
        fprintf(writing, "Camur devi: %s\n",camurDev.aciklama);
    }else if (Ork.bzdvS) {
        fprintf(writing, "Buz devi : %s\n",buzDev.aciklama);
    }else if (Ork.atsiblsS) {
        fprintf(writing, "Ates Iblisi : %s\n",atesIbl.aciklama);
    }else if (Ork.makrogS) {
        fprintf(writing, "Makrog Sava beyi : %s\n",makrog.aciklama);
    }else if (Ork.golgekrtS) {
        fprintf(writing, "Golge kurt : %s\n",golgeKurt.aciklama);
    }
    while (1) {
        Insan.totalGuc =0;
        Insan.totalSavunma=0;
        Ork.totalGuc =0;
        Ork.totalSavunma =0;
        if(sayacGENEL%5==0 && sayacGENEL != 0){
            yorgunlukSALDIRI();
            yorgunlukSAVUNMA();
        }
        fprintf(writing, "\nAdim : %d\n",sayacGENEL+1);
        test=piyade.saldiri;
        sayacPIYADE++;
        kritik(&piyade.saldiri,piyade.kritik,sayacPIYADE);
        if(test!=piyade.saldiri)
            sayacPIYADE=0;

        test=okcu.saldiri;
        sayacOKCU++;
        kritik(&okcu.saldiri,okcu.kritik,sayacOKCU);
        if(test!=okcu.saldiri)
            sayacOKCU=0;

        test=suvari.saldiri;
        sayacSUVARI++;
        kritik(&suvari.saldiri,suvari.kritik,sayacSUVARI);
        if(test!=okcu.saldiri)
            sayacSUVARI=0;

        test=kusatma.saldiri;
        sayacKUSATMA++;
        kritik(&kusatma.saldiri,kusatma.kritik,sayacKUSATMA);
        if(test!=kusatma.saldiri)
            sayacKUSATMA=0;

        test=dovuscu.saldiri;
        sayacDOVUSCU++;
        kritik(&dovuscu.saldiri,dovuscu.kritik,sayacDOVUSCU);
        if(test!=dovuscu.saldiri)
            sayacDOVUSCU=0;

        test=mizrakci.saldiri;
        sayacMIZRAKCI++;
        kritik(&mizrakci.saldiri,mizrakci.kritik,sayacMIZRAKCI);
        if(test!=mizrakci.saldiri)
            sayacMIZRAKCI=0;

        test=varg.saldiri;
        sayacVARG++;
        kritik(&varg.saldiri,varg.kritik,sayacVARG);
        if(test!=varg.saldiri)
            sayacVARG=0;
        test=troll.saldiri;
        sayacTROLL++;
        kritik(&troll.saldiri,troll.kritik,sayacTROLL);
        if(test!=troll.saldiri)
            sayacTROLL=0;

        //UNTS--------------------------------------------------------------------
        if(Insan.piyadeS){
            Insan.totalGuc += saldiri(Insan.piyadeS,piyade.saldiri);
            Insan.totalSavunma += savunma(Insan.piyadeS,piyade.savunma);
            fprintf(writing, "Piyadeler: %d birim x %.2f guc = %.2f saldiri gucu.\n",Insan.piyadeS,piyade.saldiri,piyade.saldiri*Insan.piyadeS);
            fprintf(writing, "Piyadeler: %d birim x %.2f guc = %.2f savunma gucu.\n",Insan.piyadeS,piyade.savunma,piyade.savunma*Insan.piyadeS);

        }
        if(Insan.okcuS){
            Insan.totalGuc += saldiri(Insan.okcuS,okcu.saldiri);
            Insan.totalSavunma += savunma(Insan.okcuS,okcu.savunma);
            fprintf(writing, "Okcular: %d birim x %.2f guc = %.2f saldiri gucu.\n",Insan.okcuS,okcu.saldiri,okcu.saldiri*Insan.okcuS);
            fprintf(writing, "Okcular: %d birim x %.2f guc = %.2f savunma gucu.\n",Insan.okcuS,okcu.savunma,okcu.savunma*Insan.okcuS);
        }
        if(Insan.suvariS){
            Insan.totalGuc += saldiri(Insan.suvariS,suvari.saldiri);
            Insan.totalSavunma += savunma(Insan.suvariS,suvari.savunma);
            fprintf(writing, "Suvariler: %d birim x %.2f guc = %.2f saldiri gucu.\n",Insan.suvariS,suvari.saldiri,suvari.saldiri*Insan.suvariS);
            fprintf(writing, "Suvariler: %d birim x %.2f guc = %.2f savunma gucu.\n",Insan.suvariS,suvari.savunma,suvari.savunma*Insan.suvariS);
        }
        if(Insan.makineS){
            Insan.totalGuc += saldiri(Insan.makineS,kusatma.saldiri);
            Insan.totalSavunma += savunma(Insan.makineS,kusatma.savunma);
            fprintf(writing, "Kustatma makine: %d birim x %.2f guc = %.2f saldiri gucu.\n",Insan.makineS,kusatma.saldiri,kusatma.saldiri*Insan.makineS);
            fprintf(writing, "Kustatma makine: %d birim x %.2f guc = %.2f savunma gucu.\n",Insan.makineS,kusatma.savunma,kusatma.savunma*Insan.makineS);
        }
        if(Ork.dovuscuS){
            Ork.totalGuc += saldiri(Ork.dovuscuS,dovuscu.saldiri);
            Ork.totalSavunma += savunma(Ork.dovuscuS,dovuscu.savunma);
            fprintf(writing, "Kustatma makine: %d birim x %.2f guc = %.2f saldiri gucu.\n",Ork.dovuscuS,dovuscu.saldiri,Ork.dovuscuS*dovuscu.saldiri);
            fprintf(writing, "Kustatma makine: %d birim x %.2f guc = %.2f savunma gucu.\n",Ork.dovuscuS,dovuscu.savunma,Ork.dovuscuS*dovuscu.savunma);
        }
        if(Ork.mizrakciS){
            Ork.totalGuc += saldiri(Ork.mizrakciS,mizrakci.saldiri);
            Ork.totalSavunma += savunma(Ork.mizrakciS,mizrakci.savunma);
            fprintf(writing, "Mizrakci: %d birim x %.2f guc = %.2f saldiri gucu.\n",Ork.mizrakciS,mizrakci.saldiri,Ork.mizrakciS*mizrakci.saldiri);
            fprintf(writing, "Mizrakci: %d birim x %.2f guc = %.2f savunma gucu.\n",Ork.mizrakciS,mizrakci.savunma,Ork.mizrakciS*mizrakci.savunma);
        }
        if(Ork.vargS){
            Ork.totalGuc += saldiri(Ork.vargS,varg.saldiri);
            Ork.totalSavunma += savunma(Ork.vargS,varg.savunma);
            fprintf(writing, "Varg biniciler: %d birim x %.2f guc = %.2f saldiri gucu.\n",Ork.vargS,varg.saldiri,Ork.vargS*varg.saldiri);
            fprintf(writing, "Varg biniciler: %d birim x %.2f guc = %.2f savunma gucu.\n",Ork.vargS,varg.savunma,Ork.vargS*varg.savunma);
        }
        if(Ork.trolS){
            Ork.totalGuc += saldiri(Ork.trolS,troll.saldiri);
            Ork.totalSavunma += savunma(Ork.trolS,troll.savunma);
            fprintf(writing, "Troller: %d birim x %.2f guc = %.2f saldiri gucu.\n",Ork.trolS,troll.saldiri,Ork.trolS*troll.saldiri);
            fprintf(writing, "Troller: %d birim x %.2f guc = %.2f savunma gucu.\n",Ork.trolS,troll.savunma,Ork.trolS*troll.savunma);
        }

        fprintf(writing, "\nInsan Toplam saldiri gucu: %.2f\n",Insan.totalGuc);
        fprintf(writing, "Insan Toplam savunma gucu: %.2f\n",Insan.totalSavunma);
        fprintf(writing, "Ork Toplam saldiri gucu: %.2f\n",Ork.totalGuc);
        fprintf(writing, "Ork Toplam savunma gucu: %.2f\n",Ork.totalSavunma);
        Insan.netH = net_hasar(Ork.totalGuc, Insan.totalSavunma);
        fprintf(writing, "Net Hasar:\nInsan imparatorluguna net Hasar = %.2f\n",Insan.netH);
        Ork.netH = net_hasar(Insan.totalGuc, Ork.totalSavunma);
        fprintf(writing, "Ork Legi ne net Hasar = %.2f\n",Ork.netH);

        fprintf(writing, "\nOrantili Hasar dagilimi:\n");
        if (sayacGENEL % 2 != 0) {
            fprintf(writing, "Insan Imparatorlugu :\n");
        Againinsan:
            if (Insan.piyadeS > 0) {
                hasar =hasar_dagilimi(piyade.savunma*(float)Insan.piyadeS, Insan.totalSavunma, Insan.netH) + extraHasar;
                Insan.piyadeS = Insan.piyadeS - (hasar/piyade.saglik);
                if (Insan.piyadeS < 0) {
                    extraHasar = Insan.piyadeS * piyade.saglik * -1;
                    Insan.piyadeS = 0;
                    goto Againinsan;
                }
                fprintf(writing, "Piyade hasar : %.2f\n",hasar);
            }
            if (Insan.okcuS > 0) {
                hasar =hasar_dagilimi(okcu.savunma*(float)Insan.okcuS, Insan.totalSavunma, Insan.netH)+ extraHasar;
                Insan.okcuS = Insan.okcuS - (hasar/okcu.saglik);
                if (Insan.okcuS < 0) {
                    extraHasar = Insan.okcuS * okcu.saglik * -1;
                    Insan.okcuS = 0;
                    goto Againinsan;
                }
                fprintf(writing, "Okcu hasar : %.2f\n",hasar);
            }
            if (Insan.suvariS > 0) {
                hasar =hasar_dagilimi(suvari.savunma*(float)Insan.suvariS, Insan.totalSavunma, Insan.netH)+ extraHasar;
                Insan.suvariS = Insan.suvariS - (hasar/suvari.saglik);
                if (Insan.suvariS < 0) {
                    extraHasar = Insan.suvariS * suvari.saglik * -1;
                    Insan.suvariS = 0;
                    goto Againinsan;
                }
                fprintf(writing, "Suvari hasar : %.2f\n",hasar);
            }
            if (Insan.makineS > 0) {
                hasar =hasar_dagilimi(kusatma.savunma*(float)Insan.makineS, Insan.totalSavunma, Insan.netH);
                Insan.makineS = Insan.makineS - (hasar/kusatma.saglik);
                if (Insan.makineS < 0) {
                    extraHasar = Insan.makineS * kusatma.saglik * -1;
                    Insan.makineS = 0;
                    goto Againinsan;
                }
                fprintf(writing, "Kusatma Makinesi hasar : %.2f\n",hasar);
            }
        }else{
            fprintf(writing, "Ork Legi :\n");
        Againork:
            if (Ork.dovuscuS > 0) {
                hasar =hasar_dagilimi(dovuscu.savunma*(float)Ork.dovuscuS, Ork.totalSavunma, Ork.netH);
                Ork.dovuscuS = Ork.dovuscuS - (hasar/dovuscu.saglik);
                if (Ork.dovuscuS < 0) {
                    extraHasar = Ork.dovuscuS * dovuscu.saglik * -1;
                    Ork.dovuscuS = 0;
                    goto Againork;
                }
                fprintf(writing, "Ork dovuscu hasar : %.2f\n",hasar);
            }
            if (Ork.vargS > 0) {
                hasar =hasar_dagilimi(varg.savunma*(float)Ork.vargS, Ork.totalSavunma, Ork.netH);
                Ork.vargS = Ork.vargS - (hasar/varg.saglik);
                if (Ork.vargS < 0) {
                    extraHasar = Ork.vargS * varg.saglik * -1;
                    Ork.vargS = 0;
                    goto Againork;
                }
                fprintf(writing, "Varg binici hasar : %.2f\n",hasar);
            }
            if (Ork.trolS > 0) {
                hasar = hasar_dagilimi(troll.savunma*(float)Ork.trolS, Ork.totalSavunma, Ork.netH);
                Ork.trolS = Ork.trolS - (hasar/troll.saglik);
                if (Ork.trolS < 0) {
                    extraHasar = Ork.trolS * troll.saglik * -1;
                    Ork.trolS = 0;
                    goto Againork;
                }
                fprintf(writing, "Troll hasar : %.2f\n",hasar);
            }
            if (Ork.mizrakciS > 0) {
                hasar =hasar_dagilimi(mizrakci.savunma*(float)Ork.mizrakciS, Ork.totalSavunma, Ork.netH);
                Ork.mizrakciS = Ork.mizrakciS - (hasar/mizrakci.saglik);
                if (Ork.mizrakciS < 0) {
                    extraHasar = Ork.mizrakciS * mizrakci.saglik * -1;
                    Ork.mizrakciS = 0;
                    goto Againork;
                }
                fprintf(writing, "Mizrakci hasar : %.2f\n",hasar);
            }
        }


        if (Ork.dovuscuS <= 0 && Ork.mizrakciS <= 0 && Ork.trolS <= 0 && Ork.vargS <= 0) {
            printf("\n\nInsan Imparatorlugu kazandi!!!");
            fprintf(writing,"\n\nInsan Imparatorlugu kazandi!!!");
            break;
        } else if (Insan.piyadeS <= 0 && Insan.okcuS <= 0 && Insan.suvariS <= 0 && Insan.makineS <= 0){
            printf("\n\nOrk Legi kazandi!!!");
            fprintf(writing,"\n\nOrk Legi kazandi!!!");
            break;
        }

        sayacGENEL++;
    }
    printf("\nTUR: %d",sayacGENEL +1);
    printf("\n%d",Insan.piyadeS);
    printf("\n%d",Insan.okcuS);
    printf("\n%d",Insan.suvariS);
    printf("\n%d",Insan.makineS);
    printf("\n%d",Ork.dovuscuS);
    printf("\n%d",Ork.vargS);
    printf("\n%d",Ork.mizrakciS);
    printf("\n%d",Ork.trolS);
    fclose(writing);
    }
    grafik++;
    if(grafik < 3){
        goto label;
    }




    return 0;
}

float saldiri(int birlikS,float birlikG){
    float brlkSaldiriG= birlikS*birlikG;
    return brlkSaldiriG;
}
float savunma(int brlkS,float savunmaG){
    float brlSavunmaG= brlkS*savunmaG;
    return brlSavunmaG;
}
float kritik(float *brlkSaldiriG, float krtkS,int sayac){
    if(100/krtkS<sayac){
        *brlkSaldiriG= *brlkSaldiriG*1.5;
    }
    return *brlkSaldiriG;
}
float net_hasar(float karsiSaldiri,float kendiSavunma){
    float netH=((float)1-(kendiSavunma/karsiSaldiri))*karsiSaldiri;
    if (netH < 0) {
        netH =0;
    }
    return netH;
}
float hasar_dagilimi(float birlikSav,float totalSavunma,float netH){
    float hasar = (birlikSav/totalSavunma) * netH;
    return hasar;

}
void yorgunlukSALDIRI(void){
    piyade.saldiri = piyade.saldiri*0.9;
    okcu.saldiri = okcu.saldiri*0.9;
    kusatma.saldiri = kusatma.saldiri*0.9;
    suvari.saldiri = suvari.saldiri*0.9;
    dovuscu.saldiri = dovuscu.saldiri*0.9;
    varg.saldiri = varg.saldiri*0.9;
    mizrakci.saldiri = mizrakci.saldiri*0.9;
    troll.saldiri = troll.saldiri*0.9;

}
void yorgunlukSAVUNMA(void){
    piyade.savunma = piyade.savunma*0.9;
    okcu.savunma = okcu.savunma*0.9;
    kusatma.savunma = kusatma.savunma*0.9;
    suvari.savunma = suvari.savunma*0.9;
    dovuscu.savunma = dovuscu.savunma*0.9;
    varg.savunma = varg.savunma*0.9;
    mizrakci.savunma = mizrakci.savunma*0.9;
    troll.savunma = troll.savunma*0.9;
}

void defaultValue(void){

    piyade.saglik = 0;
    piyade.savunma = 0;
    piyade.kritik = 0;
    piyade.saldiri = 0;
    okcu.saglik = 0;
    okcu.savunma = 0;
    okcu.kritik = 0;
    okcu.saldiri = 0;
    suvari.saglik = 0;
    suvari.savunma = 0;
    suvari.kritik = 0;
    suvari.saldiri = 0;
    kusatma.saglik = 0;
    kusatma.savunma = 0;
    kusatma.kritik = 0;
    kusatma.saldiri = 0;
    dovuscu.saglik = 0;
    dovuscu.savunma = 0;
    dovuscu.kritik = 0;
    dovuscu.saldiri = 0;
    varg.saglik = 0;
    varg.savunma = 0;
    varg.kritik = 0;
    varg.saldiri = 0;
    mizrakci.saglik = 0;
    mizrakci.savunma = 0;
    mizrakci.kritik = 0;
    mizrakci.saldiri = 0;
    troll.saglik = 0;
    troll.savunma = 0;
    troll.kritik = 0;
    troll.saldiri = 0;

    alp.deger = 0;
    yavuz.deger = 0;
    fatih.deger = 0;
    tugrul.deger = 0;
    mete.deger = 0;
    vrog.deger = 0;
    thruk.deger = 0;
    ugar.deger = 0;
    goruk.deger = 0;

    ejderha.deger = 0;
    agriDev.deger = 0;
    tepegoz.deger = 0;
    karakurt.deger = 0;
    samur.deger = 0;
    karaTroll.deger = 0;
    golgeKurt.deger = 0;
    camurDev.deger = 0;
    atesIbl.deger = 0;
    buzDev.deger = 0;

    Insan.piyadeS = 0;
    Insan.suvariS = 0;
    Insan.okcuS = 0;
    Insan.makineS = 0;
    Insan.alpArslnS = 0;
    Insan.yavuzS = 0;
    Insan.fatihS = 0;
    Insan.tugrulS = 0;
    Insan.meteS = 0;
    Insan.ejderhaS = 0;
    Insan.karakurtS = 0;
    Insan.samurS = 0;
    Insan.agriS = 0;
    Insan.tepegozS = 0;
    Insan.egtmpls_lvl = 0;
    Insan.sldrpls_lvl = 0;
    Insan.svnmpls_lvl = 0;
    Insan.kstmpls_lvl = 0;
    Ork.dovuscuS = 0;
    Ork.mizrakciS = 0;
    Ork.vargS = 0;
    Ork.trolS = 0;
    Ork.thrukS = 0;
    Ork.vrogS = 0;
    Ork.gorukS = 0;
    Ork.ugarS = 0;
    Ork.krtrllS = 0;
    Ork.bzdvS = 0;
    Ork.camurdvS = 0;
    Ork.golgekrtS = 0;
    Ork.atsiblsS = 0;
    Ork.egtmpls_lvl = 0;
    Ork.svnmpls_lvl = 0;
    Ork.sldrpls_lvl = 0;

    Insan.totalGuc=0;
    Insan.totalSavunma=0;
    Ork.totalGuc=0;
    Ork.totalSavunma=0;
}

//*READING_FILES***************************************************************
//---------------------------------------------------------SCENARIO--------------------------------------------------------------------
int ReadS(FILE *scenarioPr){
    scenarioPr = fopen("C:\\Users\\alpsl\\Desktop\\230202039_230202010\\indirilendosya.json", "r");
    if (scenarioPr == NULL) {
        printf("Json bulunamadý. Lütfen dosyanýn dogru isimde ve dogru dizinde oldugundan emin olun.\n");
        return 0;
    }
    char satir[256];

    while (fgets(satir,sizeof(satir),scenarioPr)){
        if (strstr(satir, "piyadeler")) {
            sscanf(satir,"      \"piyadeler\": %d,", &Insan.piyadeS);
        }else if (strstr(satir, "okcular")) {
            sscanf(satir,"            \"okcular\": %d,", &Insan.okcuS);
        }else if (strstr(satir, "suvariler")) {
            sscanf(satir,"            \"suvariler\": %d,", &Insan.suvariS);
        }else if (strstr(satir, "kusatma_makineleri")) {
            sscanf(satir,"            \"kusatma_makineleri\": %d,", &Insan.makineS);
        }else if (strstr(satir, "ork_dovusculeri")) {
            sscanf(satir,"            \"ork_dovusculeri\": %d,", &Ork.dovuscuS);
        }else if (strstr(satir, "mizrakcilar")) {
            sscanf(satir,"            \"mizrakcilar\": %d,", &Ork.mizrakciS);
        }else if (strstr(satir, "troller")) {
            sscanf(satir,"            \"troller\": %d,", &Ork.trolS);
        }else if (strstr(satir, "varg_binicileri")) {
            sscanf(satir,"            \"varg_binicileri\": %d,", &Ork.vargS);
        }else if (strstr(satir, "[\"Alparslan\"]")) {
            Insan.alpArslnS = 1;
        }else if (strstr(satir, "Fatih_Sultan_Mehmet")) {
            Insan.fatihS = 1;
        }else if (strstr(satir, "Yavuz_Sultan_Selim")) {
            Insan.yavuzS = 1;
        }else if (strstr(satir, "Tugrul_Bey")) {
            Insan.tugrulS = 1;
        }else if (strstr(satir, "Thruk_Kemikkiran")) {
            Ork.thrukS = 1;
        }else if (strstr(satir, "Vrog_Kafakiran")) {
            Ork.vrogS = 1;
        }else if (strstr(satir, "Goruk_Vahsi")) {
            Ork.gorukS = 1;
        }else if (strstr(satir, "Ugar_Zalim")) {
            Ork.ugarS = 1;
        }else if (strstr(satir, "Ejderha")) {
            Insan.ejderhaS = 1;
        }else if (strstr(satir, "Tepegoz")) {
            Insan.tepegozS = 1;
        }else if (strstr(satir, "Agri_Dagi_Devleri")) {
            Insan.agriS = 1;
        }else if (strstr(satir, "[\"Karakurt\"]")) {
            Insan.karakurtS = 1;
        }else if (strstr(satir, "Samur")) {
            Insan.samurS = 1;
        }else if (strstr(satir, "Golge_Kurtlari")) {
            Ork.golgekrtS = 1;
        }else if (strstr(satir, "Ates_Iblisi")) {
            Ork.atsiblsS = 1;
        }else if (strstr(satir, "Kara_Troll")) {
            Ork.krtrllS = 1;
        }else if (strstr(satir, "Camur_Devleri")) {
            Ork.camurdvS = 1;
        }else if (strstr(satir, "Buz_Devleri")) {
            Ork.bzdvS = 1;
        }
    }
    fseek(scenarioPr,0,SEEK_SET);
    while (fgets(satir,sizeof(satir),scenarioPr)) {
        if (strstr(satir, "insan_imparatorlugu")) {
            while (fgets(satir,sizeof(satir),scenarioPr)) {
                if(strstr(satir, "savunma_ustaligi")){
                    sscanf(satir, "      \"savunma_ustaligi\": %d",&Insan.svnmpls_lvl);
                    break;
                }else if(strstr(satir, "saldiri_gelistirmesi")){
                    sscanf(satir, "      \"saldiri_gelistirmesi\": %d",&Insan.sldrpls_lvl);
                    break;
                }else if(strstr(satir, "elit_egitim")){
                    sscanf(satir, "      \"elit_egitim\": %d",&Insan.egtmpls_lvl);
                    break;
                }else if(strstr(satir, "kusatma_ustaligi")){
                    sscanf(satir, "      \"kusatma_ustaligi\": %d",&Insan.kstmpls_lvl);
                    break;
                }
            }
        }
        else if (strstr(satir, "ork_legi")) {
            while (fgets(satir,sizeof(satir),scenarioPr)) {
                if(strstr(satir, "savunma_ustaligi")){
                    sscanf(satir, "      \"savunma_ustaligi\": %d",&Ork.svnmpls_lvl);
                    break;
                }else if(strstr(satir, "saldiri_gelistirmesi")){
                    sscanf(satir, "      \"saldiri_gelistirmesi\": %d",&Ork.sldrpls_lvl);
                    break;
                }else if(strstr(satir, "elit_egitim")){
                    sscanf(satir, "      \"elit_egitim\": %d",&Ork.egtmpls_lvl);
                    break;
                }
            }
        }
    }

    fclose(scenarioPr);
    return 0;
}
//-----------------------------------------------------------------UNIT_TYPES---------------------------------------------------------------------
int ReadU(FILE *untPr){

    untPr = fopen("C:\\Users\\alpsl\\Desktop\\230202039_230202010\\unit_types.json", "r");
    if (untPr == NULL) {
        printf("Dosya 'unit_types.json' bulunamadý. Lütfen dosyanýn dogru isimde ve dogru dizinde oldugundan emin olun.\n");
        return 0;
    }

    char control[256];


    while (fgets(control,sizeof(control),untPr)){
        int length= strlen(control);
        if(length>11){
            if(strstr(control,"insan_imparatorlugu")){
                    insanBrlk(untPr);
            }
        }
    }
        fseek(untPr,0,SEEK_SET);
    while (fgets(control,sizeof(control),untPr)){
        int length= strlen(control);
        if(length>11){
            if(strstr(control,"ork_legi")){
                orkBrlk(untPr);
            }
        }
    }
    fclose(untPr);

    return 0;
}
void insanBrlk(FILE *untPr)
{
    char control[256];
    for(int i=0; i<19; i++){
    fgets(control,sizeof(control),untPr);
    if(strstr(control,"piyadeler")){
            ozellikunt(untPr,'p');
    } else if(strstr(control,"okcular")){
            ozellikunt(untPr,'o');
    } else if(strstr(control,"suvariler")){
            ozellikunt(untPr,'s');
    } else if(strstr(control,"kusatma_makineleri")){
            ozellikunt(untPr,'k');
        }
    }


}

void orkBrlk(FILE *untPr)
{
    char control[256];
    for(int i=0; i<50; i++){
    fgets(control,sizeof(control),untPr);
    if(strstr(control,"ork_dovusculeri")){
            ozellikunt(untPr,'d');
    } else if(strstr(control,"mizrakcilar")){
            ozellikunt(untPr,'m');
    } else if(strstr(control,"varg_binicileri")){
            ozellikunt(untPr,'v');
    } else if(strstr(control,"troller")){
            ozellikunt(untPr,'t');
        }
    }

}

void ozellikunt(FILE *untPr,char brlk)
{

    int sayi =0;
    char control[256];
    for(int i=0; i<4; i++){
    fgets(control,sizeof(control),untPr);
    if(strstr(control,"saglik")){
        sscanf(control," \"saglik\": %d,\n",&sayi);
        atamaUNT(untPr,sayi,brlk,"saglik");
    } else  if(strstr(control,"savunma")){
        sscanf(control," \"savunma\": %d,\n",&sayi);
        atamaUNT(untPr,sayi,brlk,"savunma");
    } else  if(strstr(control,"saldiri")){
        sscanf(control," \"saldiri\": %d,\n",&sayi);
        atamaUNT(untPr,sayi,brlk,"saldiri");
    } else  if(strstr(control,"kritik_sans")){
        sscanf(control," \"kritik_sans\": %d,\n",&sayi);
        atamaUNT(untPr,sayi,brlk,"kritik");
        }
    }

}
void atamaUNT(FILE *thefile, int num,char brlk,char ozllk[]){
    switch (brlk) {
        case 'p':
            switch (ozllk[2]) {
                case 'g':
                    piyade.saglik = num;
                    break;
                case 'v':
                    piyade.savunma = num;
                    break;
                case 'l':
                    piyade.saldiri = num;
                    break;
                case 'i':
                    piyade.kritik = num;
                    break;
                default:
                    printf("\nERROR\n");
                    break;
            }
            break;
        case 'o':
            switch (ozllk[2]) {
                case 'g':
                    okcu.saglik = num;
                    break;
                case 'v':
                    okcu.savunma = num;
                    break;
                case 'l':
                    okcu.saldiri = num;
                    break;
                case 'i':
                    okcu.kritik = num;
                    break;
                default:
                    printf("\nERROR\n");
                    break;
            }
            break;
        case 's':
            switch (ozllk[2]) {
                case 'g':
                    suvari.saglik = num;
                    break;
                case 'v':
                    suvari.savunma = num;
                    break;
                case 'l':
                    suvari.saldiri = num;
                    break;
                case 'i':
                    suvari.kritik = num;
                    break;
                default:
                    printf("\nERROR\n");
                    break;
            }
            break;
        case 'k':
            switch (ozllk[2]) {
                case 'g':
                    kusatma.saglik = num;
                    break;
                case 'v':
                    kusatma.savunma = num;
                    break;
                case 'l':
                    kusatma.saldiri = num;
                    break;
                case 'i':
                    kusatma.kritik = num;
                    break;
                default:
                    printf("\nERROR\n");
                    break;
            }
            break;
        case 'd':
            switch (ozllk[2]) {
                case 'g':
                    dovuscu.saglik = num;
                    break;
                case 'v':
                    dovuscu.savunma = num;
                    break;
                case 'l':
                    dovuscu.saldiri = num;
                    break;
                case 'i':
                    dovuscu.kritik = num;
                    break;
                default:
                    printf("\nERROR\n");
                    break;
            }
            break;
        case 'm':
            switch (ozllk[2]) {
                case 'g':
                    mizrakci.saglik = num;
                    break;
                case 'v':
                    mizrakci.savunma = num;
                    break;
                case 'l':
                    mizrakci.saldiri = num;
                    break;
                case 'i':
                    mizrakci.kritik = num;
                    break;
                default:
                    printf("\nERROR\n");
                    break;
            }
            break;
        case 'v':
            switch (ozllk[2]) {
                case 'g':
                    varg.saglik = num;
                    break;
                case 'v':
                    varg.savunma = num;
                    break;
                case 'l':
                    varg.saldiri = num;
                    break;
                case 'i':
                    varg.kritik = num;
                    break;
                default:
                    printf("\nERROR\n");
                    break;
            }
            break;
        case 't':
            switch (ozllk[2]) {
                case 'g':
                    troll.saglik = num;
                    break;
                case 'v':
                    troll.savunma = num;
                    break;
                case 'l':
                    troll.saldiri = num;
                    break;
                case 'i':
                    troll.kritik = num;
                    break;
                default:
                    printf("\nERROR\n");
                    break;
            }
            break;
        default:
            printf("\nERROR\n");
            break;
    }
}

//--------------------------------------------------------------------HEROES----------------------------------------------------------------------
int ReadH(FILE *heroPr){
    heroPr = fopen("C:\\Users\\alpsl\\Desktop\\230202039_230202010\\heroes.json", "r");
    if (heroPr == NULL) {
        printf("Dosya 'heroes.json' bulunamadý. Lütfen dosyanýn dogru isimde ve dogru dizinde oldugundan emin olun.\n");
        return 0;
    }
    char satir[256];
        while(fgets(satir,sizeof(satir),heroPr))
        {
            if(strstr(satir,"Alparslan"))
            {
                while(1){
                  fgets(satir,sizeof(satir),heroPr);
                  if(strstr(satir,"        },")){
                     break;
                  }
                  else{
                     if(strstr(satir,"bonus_turu")){
                         sscanf(satir,"            \"bonus_turu\": \"%[^\"]\",\n",alp.bonus);
                     }else if(strstr(satir,"bonus_degeri")){
                         sscanf(satir,"            \"bonus_degeri\": \"%d\",\n",&alp.deger);
                     }else if(strstr(satir,"aciklama")){
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",alp.birim);
                     }
                  }
                }
            }
            else if(strstr(satir,"Fatih_Sultan_Mehmet"))
            {
                while(1){
                  fgets(satir,sizeof(satir),heroPr);
                  if(strstr(satir,"        },")){
                     break;
                  }
                  else{
                     if(strstr(satir,"bonus_turu")){
                         sscanf(satir,"            \"bonus_turu\": \"%[^\"]\",\n",fatih.bonus);
                     }else if(strstr(satir,"bonus_degeri")){
                         sscanf(satir,"            \"bonus_degeri\": \"%d\",\n",&fatih.deger);
                     }else if(strstr(satir,"aciklama")){
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",fatih.birim);
                     }
                  }
                }
            } else if(strstr(satir,"Mete_Han"))
            {
                while(1){
                    fgets(satir,sizeof(satir),heroPr);
                    if(strstr(satir,"        },")){
                        break;
                    }
                    else{
                        if(strstr(satir,"bonus_turu")){
                            sscanf(satir,"            \"bonus_turu\": \"%[^\"]\",\n",mete.bonus);
                        }else if(strstr(satir,"bonus_degeri")){
                            sscanf(satir,"            \"bonus_degeri\": \"%d\",\n",&mete.deger);
                        }else if(strstr(satir,"aciklama")){
                            sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",mete.birim);
                        }
                    }
                }
            } else if(strstr(satir,"Yavuz_Sultan_Selim"))
            {
                while(1){
                  fgets(satir,sizeof(satir),heroPr);
                  if(strstr(satir,"        },")){
                     break;
                  }
                  else{
                     if(strstr(satir,"bonus_turu")){
                         sscanf(satir,"            \"bonus_turu\": \"%[^\"]\",\n",yavuz.bonus);
                     }else if(strstr(satir,"bonus_degeri")){
                         sscanf(satir,"            \"bonus_degeri\": \"%d\",\n",&yavuz.deger);
                     }else if(strstr(satir,"aciklama")){
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",yavuz.birim);
                     }
                  }
                }
            }else if(strstr(satir,"Tugrul_Bey"))
            {
                while(1){
                  fgets(satir,sizeof(satir),heroPr);
                  if(strstr(satir,"    },")){
                     break;
                  }
                  else{
                     if(strstr(satir,"bonus_turu")){
                         sscanf(satir,"            \"bonus_turu\": \"%[^\"]\",\n",tugrul.bonus);
                     }else if(strstr(satir,"bonus_degeri")){
                         sscanf(satir,"            \"bonus_degeri\": \"%d\",\n",&tugrul.deger);
                     }else if(strstr(satir,"aciklama")){
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",tugrul.birim);
                     }
                  }
                }
            }else if(strstr(satir,"Goruk_Vahsi"))
            {
                while(1){
                  fgets(satir,sizeof(satir),heroPr);
                  if(strstr(satir,"        },")){
                     break;
                  }
                  else{
                     if(strstr(satir,"bonus_turu")){
                         sscanf(satir,"            \"bonus_turu\": \"%[^\"]\",\n",goruk.bonus);
                     }else if(strstr(satir,"bonus_degeri")){
                         sscanf(satir,"            \"bonus_degeri\": \"%d\",\n",&goruk.deger);
                     }else if(strstr(satir,"aciklama")){
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",goruk.birim);
                     }
                  }
                }
            }else if(strstr(satir,"Thruk_Kemikkiran"))
            {
                while(1){
                  fgets(satir,sizeof(satir),heroPr);
                  if(strstr(satir,"        },")){
                     break;
                  }
                  else{
                     if(strstr(satir,"bonus_turu")){
                         sscanf(satir,"            \"bonus_turu\": \"%[^\"]\",\n",thruk.bonus);
                     }else if(strstr(satir,"bonus_degeri")){
                         sscanf(satir,"            \"bonus_degeri\": \"%d\",\n",&thruk.deger);
                     }else if(strstr(satir,"aciklama")){
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",thruk.birim);
                     }
                  }
                }
            }else if(strstr(satir,"Vrog_Kafakiran"))
            {
                while(1){
                  fgets(satir,sizeof(satir),heroPr);
                  if(strstr(satir,"        },")){
                     break;
                  }
                  else{
                     if(strstr(satir,"bonus_turu")){
                         sscanf(satir,"            \"bonus_turu\": \"%[^\"]\",\n",vrog.bonus);
                     }else if(strstr(satir,"bonus_degeri")){
                         sscanf(satir,"            \"bonus_degeri\": \"%d\",\n",&vrog.deger);
                     }else if(strstr(satir,"aciklama")){
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",vrog.birim);
                     }
                  }
                }
            }else if(strstr(satir,"Ugar_Zalim"))
            {
                while(1){
                  fgets(satir,sizeof(satir),heroPr);
                  if(strstr(satir,"        }")){
                     break;
                  }
                  else{
                     if(strstr(satir,"bonus_turu")){
                         sscanf(satir,"            \"bonus_turu\": \"%[^\"]\",\n",ugar.bonus);
                     }else if(strstr(satir,"bonus_degeri")){
                         sscanf(satir,"            \"bonus_degeri\": \"%d\",\n",&ugar.deger);
                     }else if(strstr(satir,"aciklama")){
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",ugar.birim);
                     }
                  }
                }
            }
        }
    fclose(heroPr);

    return 0;
}

//---------------------------------------------------------------CREATURES--------------------------------------------------------------------------
int ReadC(FILE *creaturesPr){
    creaturesPr = fopen("C:\\Users\\alpsl\\Desktop\\230202039_230202010\\creatures.json", "r");
    if (creaturesPr == NULL) {
        printf("Dosya 'creatures.json' bulunamadý. Lütfen dosyanýn dogru isimde ve dogru dizinde oldugundan emin olun.\n");
        return 0;
    }

    char control[256];
    while (fgets(control,sizeof(control),creaturesPr)){
            int length=strlen(control);
            if(length>11){
                if(strstr(control,"insan_imparatorlugu")){
                        insanCnvr(creaturesPr);
                }
            }
        }
        fseek(creaturesPr,0,SEEK_SET);
        while (fgets(control,sizeof(control),creaturesPr)){
            int length=strlen(control);
            if(length>11){
                if(strstr(control,"ork_legi")){
                    orkCnvr(creaturesPr);
                }

        }}
    fclose(creaturesPr);
    return 0;
}
void insanCnvr(FILE *creaturesPr)
{
    char control[256];
    for(int i=0; i<19; i++){
    fgets(control,sizeof(control),creaturesPr);
    if(strstr(control,"Ejderha")){
            ozellikcnvr(creaturesPr,'e');
    } else if(strstr(control,"Agri_Dagi_Devleri")){
            ozellikcnvr(creaturesPr,'a');
    } else if(strstr(control,"Tepegoz")){
            ozellikcnvr(creaturesPr,'t');
    } else if(strstr(control,"Karakurt")){
            ozellikcnvr(creaturesPr,'k');
    } else if(strstr(control,"Samur")){
            ozellikcnvr(creaturesPr,'s');
        }
    }


}



void orkCnvr(FILE *creaturesPr)
{
    char control[256];
    for(int i=0; i<50; i++){
    fgets(control,sizeof(control),creaturesPr);
    if(strstr(control,"Kara_Troll")){
            ozellikcnvr(creaturesPr,'o');
    } else if(strstr(control,"Golge_Kurtlari")){
            ozellikcnvr(creaturesPr,'g');
    } else if(strstr(control,"Camur_Devleri")){
            ozellikcnvr(creaturesPr,'c');
    } else if(strstr(control,"Ates_Iblisi")){
            ozellikcnvr(creaturesPr,'i');
    } else if(strstr(control,"Buz_Devleri")){
            ozellikcnvr(creaturesPr,'b');
    } else if(strstr(control,"Makrog_Savas_Beyi")){
        ozellikcnvr(creaturesPr,'m');
}
    }

}

void ozellikcnvr(FILE *creaturesPr,char cnvr){
    int sayi;
    char kelime[100];
    char control[256];
    for(int i=0; i<4; i++){
    fgets(control,sizeof(control),creaturesPr);
    if(strstr(control,"etki_degeri")){
        sscanf(control," \"etki_degeri\": \"%d\",\n",&sayi);
        switch (cnvr) {
            case 'e':
                ejderha.deger = sayi;
                break;
            case 'a':
                agriDev.deger = sayi;
                break;
            case 't':
                tepegoz.deger = sayi;
                break;
            case 'k':
                karakurt.deger = sayi;
                break;
            case 's':
                samur.deger = sayi;
                break;
            case 'o':
                karaTroll.deger = sayi;
                break;
            case 'g':
                golgeKurt.deger = sayi;
                break;
            case 'c':
                camurDev.deger = sayi;
                break;
            case 'i':
                atesIbl.deger = sayi;
                break;
            case 'b':
                buzDev.deger = sayi;
                break;
            case 'm':
                makrog.deger = sayi;
                break;
            default:
                printf("\nERROR ozellikcnv\n");
                break;
        }
    } else  if(strstr(control,"etki_turu")){
        sscanf(control," \"etki_turu\": \"%[^\"]\",\n",kelime);
        atamacnvr(creaturesPr, cnvr, kelime,'t');
    } else  if(strstr(control,"aciklama")){
        sscanf(control," \"aciklama\": \"%[^\"]\",\n",kelime);
        atamacnvr(creaturesPr, cnvr, kelime,'a');
    }
    }

}
void atamacnvr(FILE *creaturesPr,char cnvr,char sentence[],char whichOne){
    switch (cnvr) {
        case 'e':
            if (whichOne == 't')
                strcpy(ejderha.tur, sentence);
            else{
                strcpy(ejderha.aciklama, sentence);
                }
            break;
        case 'a':
            if (whichOne == 't')
                strcpy(agriDev.tur, sentence);
            else
                strcpy(agriDev.aciklama, sentence);
            break;
        case 't':
            if (whichOne == 't')
                strcpy(tepegoz.tur, sentence);
            else
                strcpy(tepegoz.aciklama, sentence);
            break;
        case 'k':
            if (whichOne == 't')
                strcpy(karakurt.tur, sentence);
            else
                strcpy(karakurt.aciklama, sentence);
            break;
        case 's':
            if (whichOne == 't')
                strcpy(samur.tur, sentence);
            else
                strcpy(samur.aciklama, sentence);
            break;
        case 'o':
            if (whichOne == 't')
                strcpy(karaTroll.tur, sentence);
            else
                strcpy(karaTroll.aciklama, sentence);
            break;
        case 'g':
            if (whichOne == 't')
                strcpy(golgeKurt.tur, sentence);
            else
                strcpy(golgeKurt.aciklama, sentence);
            break;
        case 'c':
            if (whichOne == 't')
                strcpy(camurDev.tur, sentence);
            else
                strcpy(camurDev.aciklama, sentence);
            break;
        case 'i':
            if (whichOne == 't')
                strcpy(atesIbl.tur, sentence);
            else
                strcpy(atesIbl.aciklama, sentence);
            break;
        case 'b':
            if (whichOne == 't')
                strcpy(buzDev.tur, sentence);
            else
                strcpy(buzDev.aciklama, sentence);
            break;
        case 'm':
            if (whichOne == 't')
                strcpy(makrog.tur, sentence);
            else
                strcpy(makrog.aciklama, sentence);
            break;
        default:
            printf("\nERROR atamacnvr\n");
            break;
    }
}


//------------------------------------------------------------RESEARCH----------------------------------------------------------------------------
int ReadR(FILE *researchPr){
    researchPr = fopen("C:\\Users\\alpsl\\Desktop\\230202039_230202010\\research.json", "r");
    if (researchPr == NULL) {
        printf("Dosya 'research.json' bulunamadý. Lütfen dosyanýn dogru isimde ve dogru dizinde oldugundan emin olun.\n");
        return 0;
    }

    char satir[256];
        while(fgets(satir,sizeof(satir),researchPr))
        {
            if(strstr(satir,"savunma_ustaligi"))
            {
                while(1){
                  fgets(satir,sizeof(satir),researchPr);
                  if(strstr(satir,"        }")){
                     break;
                  }
                  else{
                     if(strstr(satir,"seviye_1")){

                        //level 1 deger
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"deger\": \"%d\",\n",&savunma_arti.level1.deger);

                         //level1 aciklama
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",savunma_arti.level1.acikla1);
                         fgets(satir,sizeof(satir),researchPr);


                     }else if(strstr(satir,"seviye_2")){

                         //level2 deger
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"deger\": \"%d\",\n",&savunma_arti.level2.deger);

                         //level2 aciklama
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",savunma_arti.level2.acikla2);
                         fgets(satir,sizeof(satir),researchPr);


                     }else if(strstr(satir,"seviye_3")){
                         //level3 deger
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"deger\": \"%d\",\n",&savunma_arti.level3.deger);

                         //level3 aciklama
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",savunma_arti.level3.acikla3);

                     }
                  }
                }
            }else if(strstr(satir,"saldiri_gelistirmesi"))
            {
                while(1){
                  fgets(satir,sizeof(satir),researchPr);
                  if(strstr(satir,"        }")){
                     break;
                  }
                  else{
                     if(strstr(satir,"seviye_1")){

                        //level 1 deger
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"deger\": \"%d\",\n",&saldiri_arti.level1.deger);

                         //level1 aciklama
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",saldiri_arti.level1.acikla1);
                         fgets(satir,sizeof(satir),researchPr);

                     }else if(strstr(satir,"seviye_2")){

                         //level2 deger
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"deger\": \"%d\",\n",&saldiri_arti.level2.deger);

                         //level2 aciklama
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",saldiri_arti.level2.acikla2);
                         fgets(satir,sizeof(satir),researchPr);


                     }else if(strstr(satir,"seviye_3")){

                         //level3 deger
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"deger\": \"%d\",\n",&saldiri_arti.level3.deger);

                         //level3 aciklama
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",saldiri_arti.level3.acikla3);
                     }
                  }
                }
            }else if(strstr(satir,"elit_egitim"))
            {
                while(1){
                  fgets(satir,sizeof(satir),researchPr);
                  if(strstr(satir,"        }")){
                     break;
                  }
                  else{
                     if(strstr(satir,"seviye_1")){

                        //level 1 deger
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"deger\": \"%d\",\n",&egitim_arti.level1.deger);

                         //level1 aciklama
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",egitim_arti.level1.acikla1);
                         fgets(satir,sizeof(satir),researchPr);

                     }else if(strstr(satir,"seviye_2")){

                         //level2 deger
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"deger\": \"%d\",\n",&egitim_arti.level2.deger);

                         //level2 aciklama
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",egitim_arti.level2.acikla2);
                         fgets(satir,sizeof(satir),researchPr);


                     }else if(strstr(satir,"seviye_3")){

                         //level3 deger
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"deger\": \"%d\",\n",&egitim_arti.level3.deger);

                         //level3 aciklama
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",egitim_arti.level3.acikla3);


                     }
                  }
                }
            }else if(strstr(satir,"kusatma_ustaligi"))
            {
                while(1){
                  fgets(satir,sizeof(satir),researchPr);
                  if(strstr(satir,"        }")){
                     break;
                  }
                  else{
                     if(strstr(satir,"seviye_1")){

                        //level 1 deger
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"deger\": \"%d\",\n",&kusatma_arti.level1.deger);

                         //level1 aciklama
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",kusatma_arti.level1.acikla1);
                         fgets(satir,sizeof(satir),researchPr);

                     }else if(strstr(satir,"seviye_2")){

                         //level2 deger
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"deger\": \"%d\",\n",&kusatma_arti.level2.deger);

                         //level2 aciklama
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",kusatma_arti.level2.acikla2);
                         fgets(satir,sizeof(satir),researchPr);


                     }else if(strstr(satir,"seviye_3")){

                         //level3 deger
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"deger\": \"%d\",\n",&kusatma_arti.level3.deger);

                         //level3 aciklama
                         fgets(satir,sizeof(satir),researchPr);
                         sscanf(satir,"            \"aciklama\": \"%[^\"]\",\n",kusatma_arti.level3.acikla3);

                     }
                  }
                }
            }
        }
    fclose(researchPr);
    return 0;
}

