#include <web.h>

Web::Web( Controller* controller ) :server( 80 ) {
    this->controller = controller;
}

void Web::init() {
    this->server.on( "/", HTTP_GET, [&]( AsyncWebServerRequest* request ) { this->render( request ); } );
    this->server.on( "^\\/playSound\\/(\\d+)$", HTTP_GET, [&]( AsyncWebServerRequest* request ) { this->playSound( request ); } );
    this->server.on( "/toggleLight", HTTP_GET, [&]( AsyncWebServerRequest* request ) { this->toggleLight( request ); } );
    this->server.on( "/toggleSound", HTTP_GET, [&]( AsyncWebServerRequest* request ) { this->toggleSound( request ); } );
    this->server.begin();
}

void Web::render( AsyncWebServerRequest* request ) {
    AsyncResponseStream* response = request->beginResponseStream( "text/html" );
    response->println( "<!DOCTYPE html><html><head><title>HalloweenD1</title>" );
    response->println( "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"/></head><body>" );
    if (controller->isLightOn()) {
        response->println( "<a href=\"/toggleLight/\"><button>Lumiere ON</button></a><br>" );
    } else {
        response->println( "<a href=\"/toggleLight/\"><button>Lumiere OFF</button></a><br>" );
    }
    if (controller->isSoundOn()) {
        response->println( "<a href=\"/toggleSound/\"><button>Son ON</button></a><br>" );
    } else {
        response->println( "<a href=\"/toggleSound/\"><button>Son OFF</button></a><br>" );
    }

    response->printf( "<a href=\"/playSound/%d\"><button>Hello And Welcome</button></a><br>\n", SOUND_HELLO_AND_WELCOME );
    response->printf( "<a href=\"/playSound/%d\"><button>Thunders</button></a><br>\n", SOUND_THUNDERS );
    response->printf( "<a href=\"/playSound/%d\"><button>Pika</button></a><br>\n", SOUND_PIKA );
    response->printf( "<a href=\"/playSound/%d\"><button>Music Ghost Buster</button></a><br>\n", MUSIC_GHOSTBUSTER );

    response->print( "</body></html>" );
    request->send( response );
}

void Web::playSound( AsyncWebServerRequest* request ) {
    this->controller->playSound( request->pathArg( 0 ).toInt() );
    this->render( request );
}

void Web::toggleLight( AsyncWebServerRequest* request ) {
    this->controller->toggleLight();
    this->render( request );
}
void Web::toggleSound( AsyncWebServerRequest* request ) {
    this->controller->toggleSound();
    this->render( request );
}

