package de.fhg.iese.capstone.carplay.middleware.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class ApplicationController {
    @GetMapping("/getApiCatalog") 
    public String getJDApiCatalog() {
        return "JD API Catalog";
    }
}