#pragma once

/*!
 * @brief Accessor
 * @param[in] Tag privateメンバにアクセスするTagクラス
 */
template <class Tag>
struct Accessor {
  typedef typename Tag::type type;  //!< メンバの型
  static type ptr_;  //!< メンバポインタ
};

/*
 * @brief staticメンバの実体
 * @param[in] Tag privateメンバにアクセスするTagクラス
 * @details
 * アクセスしたい型のメンバポインタを保持する.
 */
template <class Tag>
typename Accessor<Tag>::type Accessor<Tag>::ptr_;

/*
 * @brief Initializer
 * @param[in] Tag privateメンバにアクセスするTagクラス
 * @param[in] ptr アクセスしたい型のメンバポインタ
 * @details
 * アクセスしたい型のメンバポインタを保持する.
 */
template <class Tag, typename Tag::type ptr>
struct Initializer : Accessor<Tag> {
  /*!
   * @brief コンストラクタ
   * @details
   * Accessor型のstaticメンバ value にメンバポインタ ptr を設定する.
   */
  Initializer() {
    Accessor<Tag>::ptr_ = ptr;
  }

  static Initializer instance_;  //!< インスタンス
};

/*!
 * @brief 
 * @details
 * 自分自身の static オブジェクトの定義 explicit instantiation によって
 * main() の前に生成されることになる.
 * 生成の際に初期化を実行するためのコンストラクタが呼び出される.
 */
template <typename Tag, typename Tag::type ptr>
typename Initializer<Tag, ptr> Initializer<Tag, ptr>::instance_;
