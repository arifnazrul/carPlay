//
//  ViewController.swift
//  CallingAPI
//

import UIKit
import Alamofire

class ViewController: UIViewController {

    @IBOutlet weak var tblView: UITableView!
    let URLStr = "https://jsonplaceholder.typicode.com/posts"
    
    var resultArray = [Users]()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        callAPI()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func callAPI() {
        let url = URL(string: URLStr)
        Alamofire.request(url!, method: .get, parameters: nil, headers: nil).responseJSON { (response) in
            if let responseObj = response.value as? [[String: Any]] {
                self.resultArray = self.parseJSON(userData: responseObj)
                self.tblView.reloadData()
                print(self.resultArray)
            }
        }
    }
    
    func parseJSON(userData: [[String: Any]]) -> [Users] {
        var userArr = [Users]()
        for obj in userData {
            do {
                let data = try JSONSerialization.data(withJSONObject: obj, options: .prettyPrinted)
                let decodedData = try JSONDecoder().decode(Users.self, from: data)
                userArr.append(decodedData)
            } catch {
                
            }
        }
        return userArr
    }

}

extension ViewController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return resultArray.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath)
        cell.textLabel?.text = String(resultArray[indexPath.row].id!)
        cell.detailTextLabel?.text = resultArray[indexPath.row].userBody
        return cell
    }
    
}
