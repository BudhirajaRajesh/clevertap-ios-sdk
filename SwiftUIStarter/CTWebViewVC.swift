import SwiftUI
import UIKit
import WebKit
import CleverTapSDK

struct MyWebViewVC: UIViewControllerRepresentable {
    typealias UIViewControllerType = CTWebviewVC
    func makeUIViewController(context: Context) -> CTWebviewVC {
        let vc = CTWebviewVC()
                // Do some configurations here if needed.
        return vc
    }
    
    
    func updateUIViewController(_ uiViewController: UIViewControllerType, context: Context) {
        print(#function)
    }
}

class CTWebviewVC: UIViewController {
   
    var webView: WKWebView!

    override func viewDidLoad() {
        super.viewDidLoad()
        addWebview()

        // Do any additional setup after loading the view.
    }
    
    func addWebview() {
        let ctInterface: CleverTapJSInterface = CleverTapJSInterface(config: nil)
        self.webView = WKWebView (frame: self.view.frame)
        self.webView.configuration.userContentController.add(ctInterface, name: "clevertap")
        self.webView.loadHTMLString(self.htmlStringFromFile(with: "sampleHTMLCode"), baseURL: nil)
        self.view.addSubview(self.webView)
    }
    
    private func htmlStringFromFile(with name: String) -> String {
        let path = Bundle.main.path(forResource: name, ofType: "html")
        if let result = try? String(contentsOfFile: path!, encoding: String.Encoding.utf8) {
            return result
        }
        return ""
    }

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}
