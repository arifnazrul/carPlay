//
//  ViewController.swift
//  CallingAPI
//

import UIKit
import Alamofire
import OAuthSwift

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
        /*let url = URL(string: URLStr)
        Alamofire.request(url!, method: .get, parameters: nil, headers: nil).responseJSON { (response) in
            if let responseObj = response.value as? [[String: Any]] {
                self.resultArray = self.parseJSON(userData: responseObj)
                self.tblView.reloadData()
                print(self.resultArray)
            }
        }*/
        
        print("INIT REQUEST")
        var oauthswift = OAuth1Swift(
            consumerKey:    "johndeere-6y54WmBQS8leIBJDm6IHMCmb6aWmfZFKJ1K1ifpi",
            consumerSecret: "4a1c91e5be67cbcaebc0e49116492754a7f9c7fed98d0a81630f31d43c196655"
            
        )
        
        
        oauthswift.client.get("https://sandboxapi.deere.com/platform/",
                              success: { response in
                                print(response.dataString())
        },
                              failure: { error in
                                print("FAIL")
        }
        )
        
        print("\n\n")
        
        /*oauthswift.client.get("https://sandboxapi.deere.com/platform/organizations/449503/machines",
                              success: { response in
                                print(response.dataString())
        },
                              failure: { error in
                                print("FAIL")
        }
        )*/
        
        /*var oauthswift = OAuth1Swift(
            consumerKey:    "johndeere-6y54WmBQS8leIBJDm6IHMCmb6aWmfZFKJ1K1ifpi",
            consumerSecret: "4a1c91e5be67cbcaebc0e49116492754a7f9c7fed98d0a81630f31d43c196655",
            requestTokenUrl: "https://sandboxapi.deere.com/platform/oauth/request_token",
            authorizeUrl:    "https://sandboxapi.deere.com/platform/oauth/authorize",
            accessTokenUrl:  "https://sandboxapi.deere.com/platform/oauth/access_token"
        )
        // authorize
        let handle = oauthswift.authorize(
            withCallbackURL: URL(string: "https://sandboxapi.deere.com:443/platform")!,
            success: { credential, response, parameters in
                print(credential.oauthToken)
                print(credential.oauthTokenSecret)
                print(parameters["user_id"])
                // Do your request
        },
            failure: { error in
                print(error.localizedDescription)
        }
        )
        */
        
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
