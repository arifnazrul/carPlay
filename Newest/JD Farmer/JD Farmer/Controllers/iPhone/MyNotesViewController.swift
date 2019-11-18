//
//  MyNotesViewController.swift
//  JD Farmer
//
//  Created by June, Roselyne on 12.11.19.
//  Copyright © 2019 John Deere. All rights reserved.
//

import Foundation
import UIKit

class MyNotesViewController: UIViewController,UITableViewDataSource, UITableViewDelegate{
    
    let myarray =
        ["Call the Agronomist incharge of stadtpark field to check the soil on this field",              
         "All fields should be prunned and watered before the rainy season",
         "The field in Tripstadt has been invaded by insects and should be sprayed"]

   
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return myarray.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "mycell")
        
        cell?.textLabel?.text = myarray[indexPath.item]
        cell?.detailTextLabel?.text = myarray[indexPath.item]
        print("cellForRowAtIndexPath")
        return cell!
        
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        
        performSegue(withIdentifier: "noteDetail", sender: self)
    }
    
    @IBOutlet weak var MyTable: UITableView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        MyTable.delegate = self
        MyTable.dataSource = self
        print("Hi")
        
    }

}
