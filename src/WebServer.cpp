#include "WebServer.h"
#include "Configuration.h"
#include <deque>
#include <ESP8266WebServer.h>

namespace buddon {

////////////////////////////////////////////////////////////////
// Class : WebServer ///////////////////////////////////////////
////////////////////////////////////////////////////////////////

ESP8266WebServer web_server(HTTP_SERVER_PORT);
std::deque<std::pair<String, RequestHandler*>> mappings;

std::pair<String, RequestHandler*> *findHandlerMapping(const String &uri);
RequestHandler *findRequestHandler(const String &uri);
void handleRequest();
void handleNotFound();

WebServer::WebServer() {
  web_server.onNotFound(handleNotFound);
}

void WebServer::setup() {
  web_server.begin();
}

void WebServer::loop() {
  web_server.handleClient();
}

void WebServer::on(const String &uri, buddon::RequestHandler *handler, const bool replace_if_exists) {
  auto *mapping = findHandlerMapping(uri);
  if (nullptr != mapping) {
    // Uri is already mapped
    if (replace_if_exists) {
      mapping->second = handler;
    }
  } else {
    // Uri is fresh
    mappings.emplace_back(std::pair<String, RequestHandler*>(uri, handler));
    web_server.on(uri, handleRequest);
  }
}

std::pair<String, RequestHandler*> *findHandlerMapping(const String &uri) {
  for (auto it = mappings.begin(); it < mappings.end(); ++it) {
    if ((*it).first == uri) {
      return &(*it);
    }
  }
  return nullptr;
}

RequestHandler *findRequestHandler(const String &uri) {
  auto *mapping = findHandlerMapping(uri);
  if (nullptr != mapping) {
    return mapping->second;
  }
  return nullptr;
}

void handleRequest() {
  // TODO: read from web_server.client() stream to find the requested path
  String path = "";
  RequestHandler *mapping = findRequestHandler(path);
  if (nullptr == mapping) {
    web_server.send(500, "text/plain", "HTTP500 - Server Mapping Error");
  } else {
    // TODO: pass in path to request?
    mapping->handleRequest();
  }
}

void handleNotFound() {
  web_server.send(404, "text/plain", "HTTP404 - Not found!");
}

////////////////////////////////////////////////////////////////
// Class : RequestHandler //////////////////////////////////////
////////////////////////////////////////////////////////////////

String RequestHandler::getRequestString() {
  return web_server.client().readString();
}

////////////////////////////////////////////////////////////////
// Class : ServerDocument //////////////////////////////////////
////////////////////////////////////////////////////////////////

void ServerDocument::handleRequest() {
  // TODO: send headers using content from getHeaders()
  web_server.send(200, getContentType(), getResponseBody());
}

////////////////////////////////////////////////////////////////
// Class : HtmlDocument ////////////////////////////////////////
////////////////////////////////////////////////////////////////

HtmlDocument::HtmlDocument() {
  // TODO: add params to construct document
}

String HtmlDocument::getContentType() {
  return "text/html";
}

String HtmlDocument::getResponseBody() {
  // TODO: Generate HTML using title and body content
  return String();
}

}