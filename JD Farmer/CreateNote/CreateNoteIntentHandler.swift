/**
  - **Name**:         CreateNoteIntentHandler.swift
  - Description: This file serves as a Handler for CreateNote Intent
 
  - Author:    Ajdari, Arian [arianajdari94@gmail.com]
  - Date:      19.11.19
  - Copyright: 2019 JD Driver. All rights reserved ©
*/

import Foundation
import Intents


class CreateNoteIntentHandler: NSObject, CreateNoteIntentHandling {
    
    /**
     This function resolves date
    */
    func resolveDate(for intent: CreateNoteIntent, with completion: @escaping (INStringResolutionResult) -> Void) {
        if intent.createReminderPrompt == .yes {
            guard let date = intent.date else {
                       completion(INStringResolutionResult.needsValue())
                       return
                   }
            completion(INStringResolutionResult.success(with: date))
        }else {
            completion(INStringResolutionResult.success(with: ""))
        }
        
       
    }
    
    /**
     This function resolves reminder prompt
    */
    func resolveCreateReminderPrompt(for intent: CreateNoteIntent, with completion: @escaping (Enum5ResolutionResult) -> Void) {
        if intent.createReminderPrompt == .unknown {
            completion(Enum5ResolutionResult.needsValue())
        } else {
            completion(Enum5ResolutionResult.success(with: intent.createReminderPrompt))
        }
    }
    
    /**
     This function resolves field name
    */
    func resolveFieldName(for intent: CreateNoteIntent, with completion: @escaping (Enum2ResolutionResult) -> Void) {
        if intent.noteType == .field {
            if intent.fieldName == .unknown {
                completion(Enum2ResolutionResult.needsValue())
            } else {
                completion(Enum2ResolutionResult.success(with: intent.fieldName))
            }
        }else {
            completion(Enum2ResolutionResult.success(with: intent.fieldName))
        }
    }
    
    /**
     This function resolves note prompt
    */
    func resolveCreateNotePrompt(for intent: CreateNoteIntent, with completion: @escaping (Enum1ResolutionResult) -> Void) {
        
        if intent.createNotePrompt == .unknown {
            completion(Enum1ResolutionResult.needsValue())
        } else {
            completion(Enum1ResolutionResult.success(with: intent.createNotePrompt))
        }
    }
    
    /**
     This function handles the logic of the intent
    */
    func handle(intent: CreateNoteIntent, completion: @escaping (CreateNoteIntentResponse) -> Void) {
        if intent.createNotePrompt == .yes   {
               let createNoteController = CreateNoteController()
               if(createNoteController.createNote(intent: intent)) {
                   completion(CreateNoteIntentResponse(code: .success, userActivity: nil))
               }
           } else {
            completion(CreateNoteIntentResponse(code: .cancel, userActivity: nil))
           }
       }
       
    /**
     This function resolves note type
    */
       func resolveNoteType(for intent: CreateNoteIntent, with completion: @escaping (EnumResolutionResult) -> Void) {
        
           if intent.noteType == .unknown {
               completion(EnumResolutionResult.needsValue())
           } else {
               completion(EnumResolutionResult.success(with: intent.noteType))
           }
           
       }
       
    /**
     This function resolves content
    */
       func resolveContent(for intent: CreateNoteIntent, with completion: @escaping (INStringResolutionResult) -> Void) {
           
      
            guard let content = intent.content else {
                completion(INStringResolutionResult.needsValue())
                return
            }
            completion(INStringResolutionResult.success(with: content))
         
        
           
       }
    
    
    
    
    

}



