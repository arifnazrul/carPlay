//
//  File.swift
//  JD Farmer
//
//  Created by June, Roselyne on 11.11.19.
//  Copyright © 2019 John Deere. All rights reserved.
//

import UIKit

class mynotescontrollerview: UIViewController, UITableViewDelegate, UITableViewDataSource {
     let list = ["Call Agronomist to check all fields","Field stadtpark to be watered", "All fields to be prunned"]
    public func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return (list.count)
        
    }
    public func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell
    {
        let cell = UITableViewCell(style: UITableViewCell.CellStyle.default, reuseIdentifier:"cell");cell.textLabel?.text=list[indexPath.row]
        return(cell)
        
        
        
    }
    override func viewDidLoad() {
        super.viewDidLoad()
//do any addittional setup
    }
    override func didReceiveMemoryWarning() {
        <#code#>
    }
    }
    
    
