var aabrham = angular.module('aabrham', []);

aabrham.controller('LoginController', function LoginController($scope, $http) {
    $scope.login = function(username, password){
        $http.get("/login/api/" + username + "/" + password).then(function (result) {
            result.data.result ?
                window.location.href = "/homepage" :
                $scope.failedLogin = true

            $scope.loginError = result.data.error;
            $scope.showSignup = result.data.error.endsWith("to ");
        });
    }
});